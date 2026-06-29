// Last updated: 6/29/2026, 10:19:33 AM
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int lb = 0;
        int ub = *max_element(value.begin(), value.end());
        int n = value.size();

        const auto check = [&](int mid) -> bool {
            long long chosen = 0;
            for(int i = 0; i < n; i++) {
                if (value[i] >= mid)
                    chosen += (value[i] - mid) / decay[i] + 1;
            }  

            return (chosen >= 1LL * m);
        };
        int threshold = 0;
        while(lb <= ub) {
            int mid = ub + (lb - ub) / 2;
            if(check(mid)) {
                // true means choosen val exceed m means less need;
                threshold = mid;
                lb = mid + 1;
            } else {
                // false means choosen val less than m means more need;
                ub = mid - 1;
            }
        }
        long long res = 0;
        long long used = 0;
        for(int i = 0; i < n; i++) {
            if(threshold < value[i]) {
                int num = (value[i] - threshold - 1) / decay[i] + 1;
                used += num;
                long long last = 1LL * value[i] - 1LL * (num - 1) * decay[i];
                res = (res + (1LL * num * (value[i] + last)) / 2) % MOD;
            } 
        }

        res = (res + 1LL * (m  - used) * threshold) % MOD;

        return (int)res;
    }
};