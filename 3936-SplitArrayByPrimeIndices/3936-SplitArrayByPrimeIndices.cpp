// Last updated: 6/29/2026, 10:20:21 AM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        bitset <100001> visit;
        visit[0] = 1;
        visit[1] = 1;
    
        int n = nums.size();

        for(int i = 2; i * i < n; i++) {
            if(visit[i] == 0) {
                for(int k = i + i; k < n; k += i) {
                    visit[k] = 1;
                }
            }
        }

        long long res = 0;

        for(int i = 0; i < n; i++) {
            if(visit[i]) res += 1LL * nums[i];
            else         res -= 1LL * nums[i];
        }
        return abs(res);
    }
};