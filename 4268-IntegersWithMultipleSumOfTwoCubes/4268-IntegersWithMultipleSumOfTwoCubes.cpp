// Last updated: 6/29/2026, 10:19:39 AM
class Solution {
    using ll = long long;
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int a = 1; a <= cbrt(n); a++) {
            ll x = 1LL* a* a* a;

            for(int b = a; b <= cbrt(n); b++) {
                ll y = x + 1LL* b* b* b;

                if(y > n) break;
                mp[y]++;
            }
        }

        for(auto &[sum, freq] : mp) {
            if(freq >= 2) {
                ans.push_back(sum);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};