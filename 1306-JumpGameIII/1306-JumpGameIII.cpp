// Last updated: 5/26/2026, 12:14:27 PM
1class Solution {
2public:
3    bool canReach(vector<int>& arr, int start) {
4        
5        int n = arr.size();
6        queue<int> q;
7        q.push(start);
8
9        vector<bool> v(n, false);
10
11        while(!q.empty()) {
12            int f_elem = q.front(); q.pop();
13            
14            if(arr[f_elem] == 0) return true;
15            if(v[f_elem]) continue;
16            v[f_elem] = true; 
17            if(f_elem + arr[f_elem] < n) q.push(f_elem + arr[f_elem]);
18            if(f_elem - arr[f_elem] >= 0) q.push(f_elem - arr[f_elem]);
19
20        }
21        return false;
22    }
23};