// Last updated: 9/8/2026, 3:36:07 PM
1class Solution {
2public:
3    using ll = long long;
4    int countGoodRotations(vector<int>& nums) {
5        int n = nums.size();
6        
7        int idx1 = 0;
8        ll sum1 = 0;
9        for(int i = 0; i < n / 2; i++) {
10            sum1 += (ll)nums[i]; 
11        }
12
13        int idx2 = n / 2;
14        ll sum2 = 0;
15        for(int i = n / 2; i < n; i++) {
16            sum2 += (ll)nums[i];
17        }
18
19        int good = 0;
20        for(int i = 0; i < n; i++) {
21            if(sum1 > sum2) good += 1;
22
23            sum1 = sum1 - (ll)nums[idx1] + (ll)nums[idx2];
24            sum2 = sum2 - (ll)nums[idx2] + (ll)nums[idx1];
25            idx2 = (++idx2) % n;
26            idx1 = (++idx1) % n;
27        }
28        return good;
29    }
30};