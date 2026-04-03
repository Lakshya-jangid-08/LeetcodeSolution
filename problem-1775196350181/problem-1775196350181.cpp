// Last updated: 3/4/2026, 11:35:50 am
1class Solution {
2    int dp[100001][3];
3    int countInRange(vector<int>& v, int l, int r) {
4        auto left = lower_bound(v.begin(), v.end(), l);
5        auto right = upper_bound(v.begin(), v.end(), r);
6
7        return right - left;
8    }
9
10    int solve(int idx, int dir, vector<int>& robots, vector<int>& distance, vector<int>& walls) {
11        if(idx == robots.size()) return 0;
12
13        if(dp[idx][dir] != -1) return dp[idx][dir];
14
15        // 
16        int pos = robots[idx];
17        int dis = distance[idx];
18        if(dir == 2) {
19            // distroy left walls;
20            // cout << "dir : " << dir << "  idx :"<< idx << "  l: " << pos - dis << "  r: " << pos << "  cnt: "<<countInRange(walls, pos - dis, pos);
21            int dl = countInRange(walls, pos - dis, pos) + solve(idx + 1, 0, robots, distance, walls);
22            // distroy right walls;
23            int next = (idx + 1 == robots.size() ? 1e9 : robots[idx + 1]);
24            int dr = countInRange(walls, pos, min(pos + dis, next - 1)) + solve(idx + 1, 1, robots, distance, walls);
25
26            return dp[idx][dir] =  max(dr, dl);
27
28        } else if (dir == 1) {
29            // distroy right walls;
30            
31            int next = (idx + 1 == robots.size() ? 1e9 : robots[idx + 1]);
32            int dr = countInRange(walls, pos ,min(pos + dis, next - 1)) + solve(idx + 1, 1, robots, distance, walls);
33            // distroy left walls;
34            int prev = (idx == 0 ? -1e9 : robots[idx - 1] + distance[idx - 1] + 1);
35            int dl = countInRange(walls, max(min(prev, pos), pos - dis), pos ) + solve(idx + 1, 0, robots, distance, walls);
36            return dp[idx][dir] =  max(dr, dl);
37        } else {
38            // choose Left means dir == 0
39            int next = (idx + 1 == robots.size() ? 1e9 : robots[idx + 1]);
40            int dr = countInRange(walls, pos ,min(pos + dis, next - 1)) + solve(idx + 1, 1, robots, distance, walls);
41
42            int prev = (idx == 0 ? -1e9 : robots[idx - 1]);
43            int dl = countInRange(walls, max(prev + 1, pos - dis), pos ) + solve(idx + 1, 0, robots, distance, walls);
44
45            return dp[idx][dir] =  max(dr, dl);
46        }
47        return -1;
48    }
49public:
50    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
51        int n = robots.size();
52
53        sort(walls.begin(), walls.end());
54        vector<pair<int,int>> v;
55
56        for(int i = 0; i < robots.size(); i++) {
57            v.push_back({robots[i], distance[i]});
58        }
59
60        sort(v.begin(), v.end());
61        memset(dp, -1, sizeof(dp));
62        for(int i = 0; i < v.size(); i++) {
63            robots[i] = v[i].first;
64            distance[i] = v[i].second;
65        }
66        // idx, left/right/null 
67        
68        return solve(0, 2, robots, distance, walls);
69
70    }
71};