// Last updated: 2/4/2026, 2:42:06 am
1class Solution {
2public:
3    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
4        int n = positions.size();
5        vector<int> idx(n);
6        iota(idx.begin(), idx.end(), 0);
7
8        sort(idx.begin(), idx.end(), [&](const int l, const int r) {
9            return positions[l] < positions[r];
10        });
11
12        stack<int> s;
13
14        for(int i = 0; i < n; i++) {
15            int currIdx = idx[i];
16            int currH = healths[currIdx];
17            int currD = directions[currIdx];
18            // collision only between R & L;  x => LR, RR, LL 
19            if(currD == 'R') {
20                s.push(currIdx);
21            } else {
22                while(!s.empty() && directions[s.top()] == 'R' && healths[s.top()] < currH) {
23                    int tempIdx = s.top();
24                    healths[tempIdx] = 0;
25                    healths[currIdx]--;
26                    currH--;
27                    s.pop();
28                }
29                if(currH == 0) continue;
30                if(s.empty() || directions[s.top()] == 'L') {
31                    s.push(currIdx);
32                }
33                else if(!s.empty() && currH == healths[s.top()] && directions[s.top()] == 'R') {
34                    int tempIdx = s.top();
35                    healths[currIdx] = 0;
36                    healths[tempIdx] = 0;
37                    s.pop();
38                }
39                else {
40                    int tempIdx = s.top();
41                    healths[tempIdx]--;
42                    healths[currIdx] = 0; 
43                }
44            }
45        }
46
47        vector<int> res;
48        for(int i = 0; i < n; i++) {
49            if(healths[i] > 0) res.push_back(healths[i]);
50        }
51        return res;
52    }
53};