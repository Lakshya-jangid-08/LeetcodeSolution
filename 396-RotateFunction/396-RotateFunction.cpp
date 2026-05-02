// Last updated: 5/2/2026, 2:25:51 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        
5        int sum = accumulate(nums.begin(), nums.end(), 0);
6
7        int n = nums.size();
8        int last = n - 1;
9        int prev = 0;
10        int curr = 0;
11        
12        for(int i = 0; i < n; i++) {
13            prev += (i * nums[i]);
14        }
15        int ans = prev;
16        while(last > 0) {
17
18            curr = prev + sum - n * nums[last];
19            ans = max(ans, curr);
20            prev = curr;
21            last--;
22        } 
23
24        return ans;
25    }
26};