// Last updated: 8/29/2026, 12:23:41 AM
1class Solution {
2public:
3  void moveZeroes(vector<int>& nums) {
4      for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
5          if(nums[cur] != 0) {
6              swap(nums[lastNonZeroFoundAt++], nums[cur]);
7          }
8      }
9  }
10};