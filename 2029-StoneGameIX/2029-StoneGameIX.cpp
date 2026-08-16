// Last updated: 8/16/2026, 11:08:11 AM
1class Solution {
2public:
3    bool stoneGameIX(vector<int>& nums) {
4        int counts[3] = {0, 0, 0};
5        
6        // Count the frequencies of 0, 1, and 2 (modulo 3)
7        for (int num : nums) {
8            counts[num % 3]++;
9        }
10        
11        // If the number of 0s is EVEN
12        if (counts[0] % 2 == 0) {
13            // Alice wins if there's at least one 1 and at least one 2
14            return counts[1] > 0 && counts[2] > 0;
15        } 
16        // If the number of 0s is ODD
17        else {
18            // Alice needs a strict imbalance to overcome Bob's extra turn advantage
19            return abs(counts[1] - counts[2]) > 2;
20        }
21    }
22};