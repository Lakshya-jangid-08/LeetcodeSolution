// Last updated: 4/29/2026, 10:24:17 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;
        int needed;
        for (int i = 0; i < nums.size(); i++)
        {
            needed = target - nums[i];
            if (map.count(needed))
            {
                return {map[needed], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};