// Last updated: 6/29/2026, 10:19:11 AM
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        // if n > x =>n- x  < = k;
        // x >= n - k
        // x - n <= k
        // x <= k + n
        int sum = 0;
        for(int x = max(1,n - k); x <= k + n; x++) {
            if(x & n) continue;
            sum += x;
        }
        return sum;
    }
};