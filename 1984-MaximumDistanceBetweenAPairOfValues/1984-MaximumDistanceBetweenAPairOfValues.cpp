// Last updated: 6/29/2026, 10:21:22 AM
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // max distance;
        int n = nums1.size(), m = nums2.size();

        auto find = [&](int target, int low) -> int {
            int high = m - 1;
            int res = -1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(nums2[mid] >= target) {
                    low = mid + 1;
                    res = mid;
                } else {
                    high = mid - 1;
                }
            }
            return res;
        };
        int res = 0;
        for(int i = 0; i < n; i++) {

            int target = nums1[i];
            int j = find(target, i);
            if(j == -1) continue;
            res = max(res, j - i);
        }        
        return res;
    }
};