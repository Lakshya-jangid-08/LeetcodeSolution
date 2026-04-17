// Last updated: 4/17/2026, 5:55:58 PM
1class Solution {
2public:
3    int minMirrorPairDistance(vector<int>& nums) {
4        unordered_map<int, int> mp;
5
6        auto mirror = [&](int n) -> int {
7            string s = to_string(n);
8            reverse(s.begin(), s.end());
9            return stoi(s);
10        };
11
12        int i = 0;
13        int ans = 1e7;
14        for(auto n : nums) {
15            auto rev = mirror(n);
16            if(mp.count(n)) {
17                ans = min(ans, abs(mp[n] - i));
18            } 
19            mp[rev] = i;
20            i++;
21        }
22        return (ans == 1e7 ? - 1 : ans);
23    }
24};