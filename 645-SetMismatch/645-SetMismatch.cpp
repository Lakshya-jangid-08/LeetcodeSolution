// Last updated: 6/29/2026, 10:22:29 AM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = 0;
        int original = 0;
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(freq[i] == 2) duplicate = i;
            if(freq[i] == 0) original = i;
        }
        return {duplicate, original};
    }
};