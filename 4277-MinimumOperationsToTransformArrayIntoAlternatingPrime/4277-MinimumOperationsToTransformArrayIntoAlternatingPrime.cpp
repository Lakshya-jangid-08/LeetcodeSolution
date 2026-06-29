// Last updated: 6/29/2026, 10:19:31 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = 1e5 + 10;
        vector<bool> prime(n, false);
        prime[0] = true;
        if(n > 1) prime[1] = true;
        for(int i = 2; i * i < n ; i++) {
            if(!prime[i]) {
                for(int j = i * 2; j < n; j += i) {
                    prime[j] = true;
                }
            }
        }
        int ops = 0;
        int len = nums.size();

        vector<int> vals;

        for(int i = 0; i < n; i++) {
            if(prime[i] == true) continue;
            vals.push_back(i);
        }
        for(int i = 0; i < len; i++) {
            if(i%2 == 0) {
                // non prime
                if(prime[nums[i]]) {
                    auto it = lower_bound(vals.begin(), vals.end(), nums[i]);
                    int greater = -1e9;
                    if(it != vals.end()) {
                        greater = *it;
                    }

                    ops += abs(greater - nums[i]);
                }
            } else {
                if(!prime[nums[i]]) {
                    int curr = nums[i];
                    while(!prime[curr]) {
                        curr++;
                    }
                    ops += abs(curr - nums[i]);
                }
            }
        }
        return ops;
    }
};