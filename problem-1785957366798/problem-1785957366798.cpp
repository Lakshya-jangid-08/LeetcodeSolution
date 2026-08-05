// Last updated: 8/6/2026, 12:46:06 AM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int low = 0;
5        int mid = 0;
6        int high = nums.size() - 1;
7
8        while (mid <= high) {
9            if (nums[mid] == 0) {
10                swap(nums[low], nums[mid]);
11                low++;
12                mid++;
13            }
14            else if (nums[mid] == 1) {
15                mid++;
16            }
17            else { // nums[mid] == 2
18                swap(nums[mid], nums[high]);
19                high--;
20                // Don't increment mid here.
21            }
22        }
23    }
24};