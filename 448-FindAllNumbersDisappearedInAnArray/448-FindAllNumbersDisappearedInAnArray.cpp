// Last updated: 6/29/2026, 10:22:37 AM
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        map<int,int>  freq;
        for(int i = 0; i < n; i++) freq[nums[i]] = 1;
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 0) res.push_back(i);
        }
        return res;
    }
};