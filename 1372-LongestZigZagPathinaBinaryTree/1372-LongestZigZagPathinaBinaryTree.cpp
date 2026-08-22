// Last updated: 8/22/2026, 2:57:17 PM
1class Solution {
2public:
3    int minFlips(int a, int b, int c) {
4        
5        int count = 0;
6        for(int i = 0; i <= 31; i++) {
7            int c_bit = (c & (1 << i)) ? 1 : 0;
8            int a_bit = (a & (1 << i)) ? 1 : 0;
9            int b_bit = (b & (1 << i)) ? 1 : 0;
10
11            if((a_bit | b_bit) == c_bit) continue;
12            if(c_bit == 1) count++;
13            else {
14                count += a_bit + b_bit;
15            }
16        }
17        return count;
18    }
19};