// Last updated: 6/29/2026, 10:19:18 AM
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] % 2 != nums[j] % 2) {
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};