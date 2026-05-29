// Last updated: 5/29/2026, 12:03:07 PM
1class Solution {
2    
3    int digSum(int digit) {
4        int res = 0;
5        while(digit > 0) {
6            res += digit % 10;
7            digit /= 10;
8        }
9        return res;
10    }
11
12public:
13    int minElement(vector<int>& nums) {
14        
15        int res = 1e9;
16
17        for(int i = 0; i < nums.size(); i++) {
18            res = min(res, digSum(nums[i]));
19        }
20
21        return res;
22    }
23};