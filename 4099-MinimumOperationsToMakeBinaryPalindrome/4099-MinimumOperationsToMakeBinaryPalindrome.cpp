// Last updated: 6/29/2026, 10:20:04 AM
class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> isPalid;

        int maxElem = *max_element(nums.begin(), nums.end());
        int bits = ceil(log2(maxElem + 1));
        int last = (1 << bits) - 1;
        
        isPalid.push_back(0);
        isPalid.push_back(1);

        auto isPalindrome = [&](int x) -> bool {
            int original = x, rev = 0;

            while (x > 0) {
                rev = (rev << 1) | (x & 1);
                x = x >> 1;
            }

            return original == rev;
        };
        
        for(int i = 2; i <= last; i++) {
            if(isPalindrome(i)) {
                isPalid.push_back(i);
            }
        }

        vector<int> res;

        for(auto &n : nums) {
            
            int idx = lower_bound(isPalid.begin(), isPalid.end(), n) - isPalid.begin();
            int diff = min(abs(isPalid[idx - 1] - n), abs(n - isPalid[idx]));
            res.push_back(diff);

        }

        return res;
    }
};