// Last updated: 8/21/2026, 1:34:41 AM
1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> arr(n);
6        arr[0] = nums[0];
7        arr[n - 1] = nums[1];
8        int idx = 0, revIdx = n - 1;
9        for (int i = 2; i < n; i++) {
10            if (arr[idx] > arr[revIdx]) {
11                arr[++idx] = nums[i];
12            } else {
13                arr[--revIdx] = nums[i];
14            }
15        }
16        reverse(arr.begin() + revIdx, arr.end());
17        return arr;
18    }
19};