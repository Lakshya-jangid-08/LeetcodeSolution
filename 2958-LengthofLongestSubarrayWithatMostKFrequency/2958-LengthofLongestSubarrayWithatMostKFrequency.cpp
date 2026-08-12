// Last updated: 8/12/2026, 9:44:11 AM
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        unordered_map< int, int> freq;
5        int n = nums.size();
6        int len = 0;
7        int l = 0, r = 0;
8        while(r < n) {
9            freq[nums[r]] += 1;
10            while(freq[nums[r]] > k) {
11                freq[nums[l]]--;
12                l++;
13            }
14            len = max(len, r - l + 1);
15            r++;
16        }
17
18        return len;
19    }
20};