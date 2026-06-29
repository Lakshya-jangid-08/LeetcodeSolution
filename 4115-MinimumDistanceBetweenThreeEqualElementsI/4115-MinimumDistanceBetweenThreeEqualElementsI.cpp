// Last updated: 6/29/2026, 10:20:02 AM
class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        vector<pair<int,int>> nums;
        int i = 0;
        for(auto &it : arr) {
            nums.push_back({it, i++});
        }

        sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int r = 2;
        int res = 1e9;

        while(r < nums.size()) {
            if(nums[r].first == nums[r - 2].first) {
                res = min(res, abs(nums[r].second - nums[r - 2].second) + 
                        abs(nums[r].second - nums[r - 1].second) + 
                            abs(nums[r - 1].second - nums[r - 2].second));
            }
            r++;
        }
        return (res == 1e9 ? -1 : res);
    }
};