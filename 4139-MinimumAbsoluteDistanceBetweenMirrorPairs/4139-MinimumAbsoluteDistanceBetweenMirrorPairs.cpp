// Last updated: 6/29/2026, 10:19:58 AM
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;

        auto mirror = [&](int n) -> int {
            string s = to_string(n);
            reverse(s.begin(), s.end());
            return stoi(s);
        };

        int i = 0;
        int ans = 1e7;
        for(auto n : nums) {
            auto rev = mirror(n);
            if(mp.count(n)) {
                ans = min(ans, abs(mp[n] - i));
            } 
            mp[rev] = i;
            i++;
        }
        return (ans == 1e7 ? - 1 : ans);
    }
};