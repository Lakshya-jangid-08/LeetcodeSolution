// Last updated: 8/21/2026, 4:37:28 PM
1class Solution {
2public:
3    int splitArray(vector<int>& nums, int k) {
4        long long maxSum = accumulate(nums.begin(), nums.end(), 0LL);
5        long long minSum = *max_element(nums.begin(), nums.end());
6
7        const auto isPossible = [&](long long limit) -> bool {
8            int currSum = 0;
9            int count = 0;
10            for(int i = 0; i < nums.size(); i++) {
11                if(currSum + nums[i] > limit) {
12                    count += 1;
13                    currSum = 0;
14                }
15                currSum += nums[i];
16            }
17            if(currSum) count += 1;
18            return (count <= k);
19
20        };
21
22        int res = -1;
23        while(minSum <= maxSum) {
24            long long midSum = (minSum + maxSum) / 2;
25            if(isPossible(midSum)) {
26                maxSum = midSum - 1;
27                res = midSum;
28            } else {
29                minSum = midSum + 1;
30            }
31        }
32        return res;
33    }
34};