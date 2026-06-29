// Last updated: 6/29/2026, 10:21:17 AM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(2*n);
        int i = 0;
        for(auto val : nums) {
            res[i] = val;
            res[i + n] = val;
            i++;
        }
        return res;
    }
};