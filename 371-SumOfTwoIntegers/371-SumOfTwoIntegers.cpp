// Last updated: 6/29/2026, 10:22:47 AM
class Solution {
public:
    int getSum(int nums1, int nums2) {
        // XOR =>means Sum without Carry
        // AND => CARRY at i -1
        // Means for take Carry we have to carry and << shift (left)

        while(nums2 != 0) {
            int carry = (nums1 & nums2) << 1;
            nums1 = (nums1 ^ nums2);  //SUMATION without carry
            nums2 = carry;
        }
        return nums1;
    }
};