// Last updated: 6/29/2026, 10:23:36 AM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> res;

        res.push_back({});
        set<vector<int>> s;
        for(int mask = 1; mask < (1 << n); mask++) {
            vector<int> t;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            if(s.find(t) != s.end()) continue;
            res.push_back(t);
        }
        return res;
    }
};