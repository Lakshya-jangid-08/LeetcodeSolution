// Last updated: 5/22/2026, 11:15:06 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low = 0;
5        int high = nums.size()-1;
6
7        while(low <= high) {
8            int mid = (low + high) / 2;
9            if(nums[mid] == target) return mid;
10
11            if(nums[mid] > target) {
12                // agar mid bigger than target
13                // posibility 1. mid pivot se phle hai  
14                if(nums[0] > target) { 
15                    if(nums[0] > nums[mid]) {
16                        high = mid - 1;
17                    } else {
18                        low = mid + 1;
19                    }
20                } else {
21                    high = mid - 1;
22                }
23            } else {
24                if(nums[0] > target) {
25                    low = mid + 1;
26                } else {
27                    if(nums[mid] < nums[0]) {
28                        high=mid - 1;
29                    } else {
30                        low = mid + 1;
31                    }
32                }
33            }
34        }
35        return -1;
36    }
37};