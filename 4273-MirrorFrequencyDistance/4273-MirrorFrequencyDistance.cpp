// Last updated: 6/29/2026, 10:19:35 AM
class Solution {
public:
    int mirrorFrequency(string s) {
        int alpha[26] = {0};
        int nums[10] = {0};

        for(char &c : s) {
            if(isalpha(c)) {
                alpha[c - 'a']++;
            } else {
                nums[c - '0']++;
            }
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {
            int j = 25 - i;
            if(i < j) {
                ans += abs(alpha[i] - alpha[j]);
            }
        }

        for(int i = 0; i < 10; i++) {
            int j = 9 - i;
            if(i < j) {
                ans += abs(nums[i] - nums[j]);
            }
        }

        return ans;
    }
};