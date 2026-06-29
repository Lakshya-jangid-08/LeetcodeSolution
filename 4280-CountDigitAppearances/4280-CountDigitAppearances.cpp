// Last updated: 6/29/2026, 10:19:28 AM
class Solution {
public:

    int count(int n, int digit) {
        int cnt = 0;
        while(n > 0) {
            if(n % 10 == digit) cnt++;
            n /= 10;
        }
        return cnt;
    }
    
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for(auto n : nums) {
            cnt += count(n, digit);
        }
        return cnt;
    }
};