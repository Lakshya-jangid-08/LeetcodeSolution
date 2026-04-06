// Last updated: 6/4/2026, 11:50:27 pm
1class Solution {
2private:
3    static const long long HASH_MULTIPLIER =
4        60013;  // Slightly larger than 2 * max coordinate value
5
6    // Hash function to convert (x, y) coordinates to a unique integer value
7    long long hashCoordinates(long long x, long long y) {
8        return x + HASH_MULTIPLIER * y;
9    }
10
11public:
12    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
13        // Store obstacles in an unordered_set for efficient lookup
14        unordered_set<long long> obstacleSet;
15        for (auto& obstacle : obstacles) {
16            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
17        }
18
19        // Define direction vectors: North, East, South, West
20        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
21
22        vector<int> currentPosition = {0, 0};
23        int maxDistanceSquared = 0;
24        int currentDirection = 0;  // 0: North, 1: East, 2: South, 3: West
25
26        for (int command : commands) {
27            if (command == -1) {
28                // Turn right
29                currentDirection = (currentDirection + 1) % 4;
30                continue;
31            }
32            if (command == -2) {
33                // Turn left
34                currentDirection = (currentDirection + 3) % 4;
35                continue;
36            }
37
38            // Move forward
39            vector<int> direction = directions[currentDirection];
40            for (int step = 0; step < command; step++) {
41                int nextX = currentPosition[0] + direction[0];
42                int nextY = currentPosition[1] + direction[1];
43                if (obstacleSet.contains(hashCoordinates(nextX, nextY))) {
44                    break;
45                }
46                currentPosition[0] = nextX;
47                currentPosition[1] = nextY;
48            }
49
50            maxDistanceSquared =
51                max(maxDistanceSquared,
52                    currentPosition[0] * currentPosition[0] +
53                        currentPosition[1] * currentPosition[1]);
54        }
55
56        return maxDistanceSquared;
57    }
58};