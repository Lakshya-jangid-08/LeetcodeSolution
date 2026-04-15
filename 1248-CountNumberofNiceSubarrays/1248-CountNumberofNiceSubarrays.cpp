// Last updated: 4/15/2026, 10:09:15 PM
1class Solution {
2public:
3    int numberOfSubarrays(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int, int> prefix;
6        int cnt = 0;
7        int res = 0;
8        prefix[0] = 1;
9        for(int i = 0; i < n; i++) {
10            if(nums[i] % 2 == 1)
11                cnt++;
12
13            int target = cnt - k;
14            if(prefix.count(target)) {
15                res += prefix[target];
16            } 
17            
18            prefix[cnt]++;
19        }
20
21        return res;
22
23    }
24};