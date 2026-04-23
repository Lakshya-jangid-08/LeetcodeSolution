// Last updated: 4/23/2026, 10:00:30 AM
1class Solution {
2public:
3    vector<long long> distance(vector<int>& nums) {
4        unordered_map<int, vector<long long>> prefixSum;
5        unordered_map<int, vector<int>> mp;
6        int n = nums.size();
7        for(int i = 0; i < n; i++) {
8            mp[nums[i]].push_back(i);
9            if(prefixSum.count(nums[i]) == 0) {
10                prefixSum[nums[i]].push_back(i);
11            } else {
12                prefixSum[nums[i]].push_back( i + prefixSum[nums[i]].back() );
13            }
14        }
15
16        vector<long long> res;
17
18        for(int i = 0; i < n; i++) {
19            auto &idxArr = mp[nums[i]]; 
20            int pos = lower_bound(idxArr.begin(), idxArr.end(), i) - idxArr.begin();
21            int m = idxArr.size();
22
23            auto &psArr = prefixSum[ nums[i] ];
24
25            long long val = 1LL * i * (pos + 1) - psArr[pos]  + (psArr.back() - psArr[pos]) - 1LL * i * (m - pos - 1);
26
27            res.push_back(val);
28        }
29        return res;
30    }
31};