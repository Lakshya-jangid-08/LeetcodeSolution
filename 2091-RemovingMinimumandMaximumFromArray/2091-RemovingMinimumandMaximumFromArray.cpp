// Last updated: 8/30/2026, 1:12:59 PM
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n = nums.size();
5        int minIdx = -1, maxIdx = -1;
6        int mnv = 1e9, mxv = -1e9;
7        for(int i = 0; i < nums.size(); i++) {
8            if(mxv < nums[i]) {
9                mxv = nums[i];
10                maxIdx = i;
11            } 
12            if(mnv > nums[i]) {
13                mnv = nums[i];
14                minIdx = i;
15            }
16        }
17
18        int st1 = maxIdx + 1;
19        int ed1 = n - maxIdx;
20        int st2 = minIdx + 1;
21        int ed2 = n - minIdx;
22
23        return min({
24            max(st1, st2),
25            max(ed1, ed2),
26            st1 + ed2,
27            st2 + ed1
28        });
29    }
30};