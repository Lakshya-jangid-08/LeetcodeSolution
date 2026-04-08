// Last updated: 8/4/2026, 11:02:56 pm
1class Solution {
2public:
3    bool containsNearbyDuplicate(vector<int>& nums, int k) {
4        unordered_map<int, int> mp;
5
6        for(int i = 0; i <= min(k, (int)nums.size() - 1); i++) {
7            if(mp.count(nums[i])) return true;
8            mp[nums[i]]++;
9        }
10        int l = 0;
11        for(int i = k + 1; i < nums.size(); i++) {
12            mp[nums[l]]--;
13            if(mp[nums[l]] == 0) mp.erase(nums[l]);
14            l++;
15            if(mp.count(nums[i])) return true;
16            mp[nums[i]]++;
17        }
18        return false;
19    }
20};