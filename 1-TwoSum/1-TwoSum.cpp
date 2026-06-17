// Last updated: 6/17/2026, 6:05:37 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target)
4    {
5        unordered_map<int, int> map;
6        int needed;
7        for (int i = 0; i < nums.size(); i++)
8        {
9            needed = target - nums[i];
10            if (map.count(needed))
11            {
12                return {map[needed], i};
13            }
14            map[nums[i]] = i;
15        }
16        return {};
17    }
18};