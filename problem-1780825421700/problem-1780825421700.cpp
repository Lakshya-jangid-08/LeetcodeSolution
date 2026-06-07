// Last updated: 6/7/2026, 3:13:41 PM
1class Solution {
2public:
3    int sumOfGoodIntegers(int n, int k) {
4        // if n > x =>n- x  < = k;
5        // x >= n - k
6        // x - n <= k
7        // x <= k + n
8        int sum = 0;
9        for(int x = max(1,n - k); x <= k + n; x++) {
10            if(x & n) continue;
11            sum += x;
12        }
13        return sum;
14    }
15};