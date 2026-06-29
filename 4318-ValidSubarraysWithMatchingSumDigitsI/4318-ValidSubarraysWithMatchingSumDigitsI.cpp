// Last updated: 6/29/2026, 10:19:12 AM
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int cnt = 0;

        const auto isValid = [&](long long sum) -> bool {
            int last = sum % 10;
            long long first = sum;
            while (first >= 10) first /= 10;
            return first == x && last == x;
        };
        
        for(int ws = 1; ws <= n; ws++) {
            int l = 0, r = 0;
            long long sum = 0;
            while(r < ws) {
                sum += 1LL * nums[r];
                r++;
            }
            
            if(isValid(sum)) cnt++;
            while(r < nums.size()) {
                sum -= 1LL * nums[l++];
                sum += 1LL * nums[r++];

                // check is sum valid;
                if(isValid(sum)) cnt++;
                
            }
            
        }
        return cnt;
        
    }
};