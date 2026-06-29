// Last updated: 6/29/2026, 10:22:55 AM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> helper;

        for(auto it : nums) {
            if(helper.empty() || it > helper.back()) {
                helper.push_back(it);
            } else {
                auto idx = lower_bound(helper.begin(), helper.end(), it) - helper.begin();
                helper[idx] = it;
            }
        }
        return helper.size();
    }
};