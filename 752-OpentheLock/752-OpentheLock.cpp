// Last updated: 8/25/2026, 2:48:18 PM
1class Solution {
2
3struct Node {
4    int x;
5    int y;
6    int keyCounts;
7    vector<int> keys;
8    int moves;
9
10    Node(int x, int y, int keyCounts, vector<int> keys, int moves)
11        : x(x), y(y), keyCounts(keyCounts), keys(keys), moves(moves) {}
12
13    bool operator<(const Node& other) const {
14        if(moves == other.moves) 
15            return keyCounts < other.keyCounts;
16        return moves > other.moves;
17    }
18};
19
20public:
21    int shortestPathAllKeys(vector<string>& grid) {
22        priority_queue<Node> pq;
23        int keyNum = 0;
24
25        int n = grid.size(), m = grid[0].size();
26        vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(64, false)));
27
28        for(int i = 0; i < grid.size(); i++) {
29            for(int j = 0; j < m; j++) {
30                if(97 <= grid[i][j] && grid[i][j] <= 102) keyNum += 1; 
31                if(grid[i][j] == '@') {
32                    vector<int> initialKeys(6, 0);
33                    pq.push({i, j, 0, initialKeys, 0});
34                }
35            }
36        }
37
38
39        int dx[] = {-1, 0, 1, 0};
40        int dy[] = {0, -1, 0, 1};
41
42        while(!pq.empty()) {
43            
44            auto currNode = pq.top(); pq.pop();
45            int x = currNode.x, y = currNode.y, keyCounts = currNode.keyCounts, moves = currNode.moves;
46            vector<int> keys = currNode.keys;
47
48            int mask = 0;
49            for(int k = 0; k < 6; k++) {
50                if(keys[k] == 0) continue;
51                mask |= (1 << k);
52            }
53
54            if(keyCounts == keyNum) return moves;
55
56            for(int i = 0; i < 4; i++) {
57                int nx = x + dx[i];
58                int ny = y + dy[i];
59
60                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
61                if(grid[nx][ny] == '#') continue;
62                // if has .
63
64                if(grid[nx][ny] == '.' || grid[nx][ny] == '@') {
65                    if(visit[nx][ny][mask]) continue;
66                    visit[nx][ny][mask] = true;
67
68                    pq.push({nx, ny, keyCounts, keys, moves + 1});
69                }
70                else if(97 <= grid[nx][ny] && grid[nx][ny] <= 102) {
71                    int kv = grid[nx][ny] - 97;
72                    keys[kv] += 1;
73
74                    if(keys[kv] == 1) {
75                        keyCounts += 1;
76                    }
77
78                    int newMask = 0;
79                    for(int k = 0; k < 6; k++) {
80                        if(keys[k] == 0) continue;
81                        newMask |= (1 << k);
82                    }
83
84                    if(visit[nx][ny][newMask]) {
85                        keys[kv] -= 1;
86                        if(keys[kv] == 0) {
87                            keyCounts -= 1;
88                        }
89                        continue;
90                    }
91                    visit[nx][ny][newMask] = true;
92
93                    pq.push({nx, ny, keyCounts, keys, moves + 1});
94                    
95                    keys[kv] -= 1;
96                    if(keys[kv] == 0) {
97                        keyCounts -= 1;
98                    }
99                }
100                else {
101                    int kv = grid[nx][ny] - 'A';
102                    if(keys[kv] == 0) continue;
103                    if(visit[nx][ny][mask]) continue;
104                    visit[nx][ny][mask] = true;
105                    pq.push({nx, ny, keyCounts, keys, moves + 1});
106                }
107            }
108        }
109        return -1;
110    }
111};