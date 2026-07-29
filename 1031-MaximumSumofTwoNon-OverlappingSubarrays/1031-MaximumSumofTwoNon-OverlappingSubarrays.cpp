// Last updated: 7/29/2026, 11:48:35 AM
1class Solution {
2public:
3    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
4        int n = nums.size();
5        vector<int> ps1(n, 0), ps2(n, 0);
6
7        const auto insertValues = [&](int len, vector<int> & ps) -> void {
8            int idx = 0, r = 0, l = 0;
9            while(r < len) {
10                ps[idx] += nums[r++]; 
11            }
12            idx++;
13            while(r < n) {
14                ps[idx] = ps[idx - 1] + nums[r] - nums[l];
15                l++; r++; idx++;
16            }
17        };
18
19        int res = 0;
20        const auto calc = [&](vector<int> & nums1, int len1, vector<int> & nums2, int len2) {
21            for(int i = 0; i < n; i++) {
22                int currIdx = i + len1;
23                while(currIdx < n) {
24                    res = max(res, nums1[i] + nums2[currIdx++]); 
25                }
26            }
27        };
28
29        insertValues(firstLen, ps1);
30        insertValues(secondLen, ps2);
31
32        calc(ps1, firstLen, ps2, secondLen);
33        calc(ps2, secondLen, ps1, firstLen);
34
35        return res;
36    }   
37};