// Last updated: 6/29/2026, 10:21:40 AM
class Solution {
    int MOD = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();   
        vector<int> pow(n, -1);
        pow[0] = 1;
       
        for(int i = 1; i < n; i++) {
            pow[i] = (pow[i - 1] * 2LL) % MOD;
        }
        sort(nums.begin(),nums.end());
       
        int l = 0;
        int r = n-1;
        long int res = 0;
        
        while(l <= r) {
            if(nums[l] + nums[r] > target) {
                r--;
            } else {
                // calc value
                res += pow[r - l];
                res %= MOD;
                // go ahead
                l++;
            }
        }
        return res;
    }
};