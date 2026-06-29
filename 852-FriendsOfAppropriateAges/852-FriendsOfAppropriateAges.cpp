// Last updated: 6/29/2026, 10:22:10 AM
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121, 0);

        for(auto &age : ages) {
            cnt[age]++;
        }   

        int res = 0;
        for(int a = 1; a < 121; a++) {
            for(int b = 1; b < 121; b++) {
                if( a <= 0.5 * b + 7 ) continue;
                if(a > b) continue;
                if(a > 100 && b < 100) continue;

                res += cnt[a] * cnt[b];

                if(a == b) res -= cnt[a];
            }
        }

        return res;
    }
};