// Last updated: 8/26/2026, 10:37:34 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target)
4    {
5        unordered_map<int, int> map;
6        int need;
7        for (int i = 0; i < nums.size(); i++)
8        {
9            need = target - nums[i];
10            if (map.count(need))
11            {
12                return {map[need], i};
13            }
14            map[nums[i]] = i;
15        }
16        return {};
17    }
18};