// Last updated: 11/4/2026, 6:16:22 pm
1class Solution {
2public:
3    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
4        set<long long> s;
5
6        int r = 0, l = 0;
7
8        while(r < nums.size()) {
9            auto it = s.lower_bound(nums[r] - valueDiff);
10            if(it != s.end() && abs(1LL * nums[r] - 1LL * *it) <= valueDiff) return true;
11
12            s.insert(nums[r]);
13            if(r - l >= indexDiff) {
14                s.erase(nums[l]);
15                l++;
16            }
17            r++;
18        }
19        return false;
20    }
21};