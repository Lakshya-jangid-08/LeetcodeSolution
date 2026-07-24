// Last updated: 7/24/2026, 10:09:54 AM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5        if(n==1) return 1;
6        unordered_set<int> s;
7
8        for(int j = 0; j < n; j++) {
9            for(int k = j + 1; k < n; k++) {
10                s.insert(nums[j] ^ nums[k]);
11            }
12        }
13        unordered_set<int> res;
14        for(int i = 0; i < n; i++) {
15            for(auto v : s) {
16                res.insert(v ^ nums[i]);
17            }
18        }
19
20        return res.size();
21    }
22};