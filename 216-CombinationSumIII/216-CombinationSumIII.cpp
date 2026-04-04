// Last updated: 4/4/2026, 1:20:20 pm
1class Solution {
2    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
3    set<vector<int>> res;
4
5    void solve(int k, int n, int idx, vector<int> &temp) {
6
7        if(n == 0 && k == 0) {
8            res.insert(temp);
9            return;
10        }
11        if(n < 0 || k < 0 || idx == 9) return;
12        
13        temp.push_back(nums[idx]);
14        solve(k - 1, n - nums[idx], idx + 1, temp);
15        temp.pop_back();
16        
17        solve(k, n, idx + 1, temp);
18        
19        return ;
20    } 
21
22public:
23    vector<vector<int>> combinationSum3(int k, int n) {
24        if(k > n) return {};
25        if(n > 46) return {};
26        vector<int> temp;
27        solve(k, n, 0, temp);
28
29        return vector<vector<int>>(res.begin(), res.end());
30    }
31};