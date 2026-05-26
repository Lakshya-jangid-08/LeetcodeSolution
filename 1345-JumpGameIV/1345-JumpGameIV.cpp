// Last updated: 5/26/2026, 12:39:28 PM
1class Solution {
2public:
3    int minJumps(vector<int>& nums) {
4        
5        int n = nums.size();
6        unordered_map<int, vector<int>> idxmp;
7        
8        for(int i = 0; i < n; i++) {
9            idxmp[nums[i]].push_back(i);
10        }
11
12        queue<int> q;
13        vector<bool> visit(n, false);
14
15        q.push(0);
16        int ans = 0;
17        while(!q.empty()) {         
18            int len  = q.size();
19            while(len--) {
20                int idx = q.front(); q.pop();
21
22                if(idx == n - 1) return ans;
23                
24                visit[idx] = true;
25
26                if(idx > 0 && visit[idx - 1] != true) {
27                    q.push(idx - 1);
28                    visit[idx - 1] = true;
29                } 
30
31                if(idx < n - 1 && visit[idx + 1] != true) {
32                    q.push(idx + 1);
33                    visit[idx + 1] = true;
34                }
35
36                for(auto idx2 : idxmp[nums[idx]]) {
37                    if(visit[idx2]) continue;
38                    q.push(idx2);
39                    visit[idx2] = true;
40                }
41
42                idxmp[nums[idx]].clear();
43            }
44            ans += 1;
45        }
46        return ans;
47    }
48};