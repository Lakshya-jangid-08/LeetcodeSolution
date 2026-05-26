// Last updated: 5/26/2026, 9:04:10 AM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n = nums.size();
5        if(n <= 1) return 0;
6        int maxReach = 0, curr_jump = 0, ans = 0;
7        for(int i = 0; i < n; i++) {
8            maxReach = max(maxReach, i + nums[i]);
9
10            if(curr_jump == i) {
11                ans += 1;
12                curr_jump = maxReach;
13            }
14
15            if(curr_jump >= n - 1) break;
16
17        }
18        return ans;
19    }
20};