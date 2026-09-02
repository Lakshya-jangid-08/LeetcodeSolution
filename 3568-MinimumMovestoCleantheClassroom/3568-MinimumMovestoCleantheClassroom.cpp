// Last updated: 9/2/2026, 10:11:34 AM
1class Solution {
2public:
3    int minMoves(vector<string>& classroom, int energy) {
4        int n = classroom.size(), m = classroom[0].size();
5        int num = 0;
6        struct Node {int x, y, eng, mask;};
7        queue<Node> q;
8
9        int x = 0;
10        int totalKey = 0;
11        int sx = 0, sy = 0;
12        for(auto & cord : classroom) {
13            int y = 0;
14            for(auto & ch : cord) {
15                if(ch == 'S') {
16                    q.push({x, y, energy, 0});
17                    sx = x; sy = y;
18                }
19                if(ch == 'L') {
20                    ch = num + '0';
21                    totalKey++;
22                    num++;
23                }
24                y++;
25            }
26            x++;
27        }
28
29        vector<vector<vector<int>>> bestEng(n, vector<vector<int>>(m, vector<int>(1 << num, -1)));
30        bestEng[sx][sy][0] = energy;
31
32        int dx[] = {-1, 0, 1, 0};
33        int dy[] = {0, -1, 0, 1};
34        int operation = 0;
35
36        while(!q.empty()) {
37            int len = q.size();
38            while(len--) {
39                auto [x, y, eng, mask] = q.front(); q.pop();
40                // cout << x << " " << y << " " << eng << " : " << maskMP[x][y] << endl;
41                if(mask == (1 << num) - 1) return operation;
42                if(eng == 0) continue;
43                for(int i = 0; i < 4; i++) {
44                    int nx = x + dx[i];
45                    int ny = y + dy[i];
46
47                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
48                    if(classroom[nx][ny] == 'X') continue;
49                   
50                    int neng = (classroom[nx][ny] == 'R') ? energy : eng - 1;
51                    int updatedMask = mask;
52                    if(classroom[nx][ny] >= '0' && classroom[nx][ny] <= '9') {
53                        int v = classroom[nx][ny] - '0';
54                        updatedMask |= (1 << v);
55                    }
56
57                    if(bestEng[nx][ny][updatedMask] >= neng) continue;
58                    bestEng[nx][ny][updatedMask] = neng;
59                    q.push({nx, ny, neng, updatedMask});
60
61                }
62            }
63            // cout << endl;
64            operation++;
65        }
66        return -1;
67    }
68};