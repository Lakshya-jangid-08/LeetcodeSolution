// Last updated: 6/9/2026, 12:03:36 PM
1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        
5        int res = INT_MAX;
6        int n = nums.size();
7
8        vector<int> diff(2 * limit + 2, 0);
9
10        for(int i = 0; i < n / 2; i++) {
11
12            int maxVal = max(nums[i], nums[n - i - 1]) + limit;
13            int minVal = min(nums[i], nums[n - i - 1]) + 1;
14
15            // 2's moves
16            diff[2] += 2;
17            diff[2* limit + 1] -= 2;
18            
19            // 1's moves;
20            diff[minVal] += (-1);
21            diff[maxVal + 1] += 1;
22
23            int pairSum = nums[i] + nums[n - 1 - i];
24            
25            // 0's moves
26            diff[pairSum] += (-1);
27            diff[pairSum + 1] += 1;
28        }
29
30        for(int i = 2; i <= 2 * limit; i++) {
31            diff[i] += diff[i - 1];
32            res = min(res, diff[i]);
33        }
34        return res;
35    }
36};