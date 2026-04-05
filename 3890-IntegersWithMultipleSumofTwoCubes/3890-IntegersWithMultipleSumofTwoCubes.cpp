// Last updated: 5/4/2026, 10:30:32 am
1class Solution {
2    using ll = long long;
3public:
4    vector<int> findGoodIntegers(int n) {
5        unordered_map<int, int> mp;
6        vector<int> ans;
7        for(int a = 1; a <= cbrt(n); a++) {
8            ll x = 1LL* a* a* a;
9
10            for(int b = a; b <= cbrt(n); b++) {
11                ll y = x + 1LL* b* b* b;
12
13                if(y > n) break;
14                mp[y]++;
15            }
16        }
17
18        for(auto &[sum, freq] : mp) {
19            if(freq >= 2) {
20                ans.push_back(sum);
21            }
22        }
23
24        sort(ans.begin(), ans.end());
25        return ans;
26    }
27};