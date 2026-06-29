// Last updated: 6/29/2026, 10:23:18 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *partition_point(nums.begin(), nums.end(), [&](int n) { return n > nums.back(); });
    }
};