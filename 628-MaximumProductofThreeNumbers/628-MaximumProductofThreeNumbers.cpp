// Last updated: 7/27/2026, 2:14:41 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int fm = -1;
5        int sm = -1;
6
7        int n = nums.size();
8        for(int i = 0 ; i<n ; i++){
9            if(nums[i] >= fm){
10                sm = fm;
11                fm = nums[i];
12            }
13            else if(nums[i] >= sm){
14                sm = nums[i];
15            }
16        }
17        return (fm - 1) * (sm - 1);
18    }
19};