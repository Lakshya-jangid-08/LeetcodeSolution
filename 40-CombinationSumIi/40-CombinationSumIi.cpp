// Last updated: 6/29/2026, 10:23:48 AM
class Solution {
    set<vector<int>> res;
    void solve(vector<int> &nums, int idx, int target, vector<int>& temp) {
        if(target == 0) {
            res.insert(temp);
            return;
        }
        if(target < 0 || idx == nums.size()) return;

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i-1] == nums[i])   continue;
            if(target - nums[i] >= 0) {
                temp.push_back(nums[i]);
                solve(nums, i + 1, target - nums[i], temp);
                temp.pop_back();
            } else {
                break;
            }
        }

        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, 0, target, temp);
        return vector<vector<int>> (res.begin(), res.end());
    }
};