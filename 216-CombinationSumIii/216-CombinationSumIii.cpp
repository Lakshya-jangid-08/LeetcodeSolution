// Last updated: 6/29/2026, 10:23:02 AM
class Solution {
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<vector<int>> res;

    void solve(int k, int n, int idx, vector<int> &temp) {

        if(n == 0 && k == 0) {
            res.insert(temp);
            return;
        }
        if(n < 0 || k < 0 || idx == 9) return;
        
        temp.push_back(nums[idx]);
        solve(k - 1, n - nums[idx], idx + 1, temp);
        temp.pop_back();
        
        solve(k, n, idx + 1, temp);
        
        return ;
    } 

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > n) return {};
        if(n > 46) return {};
        vector<int> temp;
        solve(k, n, 0, temp);

        return vector<vector<int>>(res.begin(), res.end());
    }
};