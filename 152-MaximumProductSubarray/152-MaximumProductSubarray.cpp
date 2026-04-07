// Last updated: 8/4/2026, 1:54:40 am
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int res = INT_MIN, temp = 0;
5        for(int i = 0; i < nums.size(); i++)  {
6            temp *= nums[i];
7            if(temp == 0) {
8                temp = nums[i];
9            }
10            res = max(res, temp);
11        }
12        temp = 0;
13        for(int i = nums.size() - 1; i >= 0; i--)  {
14            temp *= nums[i];
15            if(temp == 0) {
16                temp = nums[i];
17            }
18            res = max(res, temp);
19        }
20
21
22        return res;
23    }
24};