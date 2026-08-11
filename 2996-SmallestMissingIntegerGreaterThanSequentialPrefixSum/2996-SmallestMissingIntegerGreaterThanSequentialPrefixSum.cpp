// Last updated: 8/11/2026, 2:55:53 PM
1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4        unordered_map<int, bool> mp;
5        for(const auto &n : nums) mp[n] = 1;
6        int sum = nums[0];
7        for(int i = 1; i < nums.size(); i++) {
8            if(nums[i] != nums[i - 1] + 1) break;
9            sum += nums[i];
10        }   
11
12        auto it = mp.find(sum);
13        while(it != mp.end()) {
14            sum += 1;
15            it = mp.find(sum);
16        }
17
18        return sum;
19
20    }
21};