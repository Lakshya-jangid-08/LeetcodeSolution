// Last updated: 6/29/2026, 10:23:49 AM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] > target) {
                // agar mid bigger than target
                // posibility 1. mid pivot se phle hai  
                if(nums[0] > target) { 
                    if(nums[0] > nums[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    high = mid - 1;
                }
            } else {
                if(nums[0] > target) {
                    low = mid + 1;
                } else {
                    if(nums[mid] < nums[0]) {
                        high=mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};