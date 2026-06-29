// Last updated: 6/29/2026, 10:23:55 AM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int r = n - 1;

                while(l < r) {
                    long long curr = 1LL * nums[i] + 1LL * nums[j] + 1LL * nums[l] + 1LL * nums[r];
                    if(curr == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l - 1]) l++;
                        while(l < r && nums[l] == nums[r + 1]) r--;
                    }
                    else if (curr > target) {
                        r--;
                    }
                    else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};