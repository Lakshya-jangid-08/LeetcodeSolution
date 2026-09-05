// Last updated: 9/5/2026, 10:37:52 PM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> left(n), right(n);
6
7        left[0] = nums[0];
8
9        for(int i = 1; i < n; i++) {
10            left[i] = max(left[i - 1], nums[i]);
11        }
12        right[n-1] = nums[n-1];
13        for(int i = n - 2; i >= 0; i--) {
14            right[i] = min(right[i + 1], nums[i]);
15        }
16
17        for(int i = 0; i < n; i++) {
18            if(left[i] - right[i] <= k) {
19                return i;
20            }
21        }
22        return -1;
23    }
24};