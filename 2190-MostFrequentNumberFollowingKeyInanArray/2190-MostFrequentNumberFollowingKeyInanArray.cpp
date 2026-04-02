// Last updated: 2/4/2026, 6:48:05 pm
1class Solution {
2public:
3    int mostFrequent(vector<int>& nums, int key) {
4        unordered_map<int, int> mp;
5        int n = nums.size();
6
7        int mx = 0, res = -1;
8
9        for(int i = 0; i < n - 1; i++) {
10            if(nums[i] == key) {
11                mp[nums[i + 1]]++;
12
13                if(mp[nums[i + 1]] > mx) {
14                    mx = mp[nums[i + 1]];
15                    res = nums[i + 1];
16                }
17            }
18        }
19
20        return res;
21    }
22};