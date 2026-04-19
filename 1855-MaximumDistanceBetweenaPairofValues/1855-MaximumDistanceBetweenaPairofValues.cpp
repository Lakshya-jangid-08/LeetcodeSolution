// Last updated: 4/19/2026, 10:53:12 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
4        // max distance;
5        int n = nums1.size(), m = nums2.size();
6
7        auto find = [&](int target, int low) -> int {
8            int high = m - 1;
9            int res = -1;
10            while(low <= high) {
11                int mid = (low + high) / 2;
12                if(nums2[mid] >= target) {
13                    low = mid + 1;
14                    res = mid;
15                } else {
16                    high = mid - 1;
17                }
18            }
19            return res;
20        };
21        int res = 0;
22        for(int i = 0; i < n; i++) {
23
24            int target = nums1[i];
25            int j = find(target, i);
26            if(j == -1) continue;
27            res = max(res, j - i);
28        }        
29        return res;
30    }
31};