// Last updated: 6/29/2026, 10:19:53 AM
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        unsigned long long sum = nums[0]; 
        for(int i = 1; i < n - 1; i++) {
            sum = sum + (unsigned long long)nums[i];
        }
        // cout << n;
        int ans = -1;
        unsigned long long prod = 1;
        for(int i = n - 1; i > 0; i--) {
            // prev sum;
            if(sum == prod) ans = i;
            if(sum < prod) return ans;
            if(prod > ULLONG_MAX / nums[i]) return ans;
            prod = prod * (unsigned long long)nums[i];
            sum -= nums[i - 1];
        }

        return ans;
    }
};