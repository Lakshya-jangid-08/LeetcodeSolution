// Last updated: 6/29/2026, 10:23:35 AM
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> s;
        res.push_back({});

        int n = nums.size();

        for(int mask = 1; mask < (1 << n); mask++) {
            vector<int> temp;
            for(int idx = 0; idx < n; idx++) {
                if(mask & (1 << idx)) {
                    temp.push_back(nums[idx]);
                }
            }
            if(s.find(temp) != s.end()) continue;
            s.insert(temp);
            res.push_back(temp); 
        }

        return res;
    }
};