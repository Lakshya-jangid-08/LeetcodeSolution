// Last updated: 8/23/2026, 10:58:48 PM
1class Solution {
2public:
3    bool canPartitionKSubsets(vector<int>& nums, int k) {
4        int n = nums.size(); 
5        vector<int> bucket_partial_sum(1 << n, 0); 
6        int total_sum = 0; 
7        for(int i = 0;i < n; i++){
8            total_sum += nums[i]; 
9        }
10        if(total_sum % k) return false; 
11        int t_sum = total_sum / k; 
12        for(int i = 1; i < (1 <<n); i++) {
13            int sum = 0; 
14            for(int j = 0; j < n; j++){
15                if(i & (1 << j)){
16                    sum += nums[j]; 
17                }
18            }
19            bucket_partial_sum[i] = sum % t_sum; 
20        }
21
22        vector<bool> dp(1 << n, false); 
23        dp[0] = true; 
24        for(int mask = 1; mask < (1 << n); mask++){
25            for(int i = 0;i < n; i++) {
26                if(!(mask & (1 << i))) continue; 
27
28                int prev_mask = mask & (~(1 << i)); 
29                if(dp[prev_mask] && (nums[i] + bucket_partial_sum[prev_mask] <= t_sum)){
30                    dp[mask] = true; 
31                }
32            }
33        }
34
35        return dp[(1 << n) - 1]; 
36    }
37};