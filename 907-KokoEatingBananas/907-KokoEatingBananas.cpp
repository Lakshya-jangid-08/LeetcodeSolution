// Last updated: 6/29/2026, 10:22:05 AM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = *max_element(piles.begin(), piles.end());

        long long ans = -1;


        auto isPos = [&](long long mid) -> bool {

            long long cnt = 0;

            for(auto p : piles) {
                cnt += (p + mid - 1) / mid;
            }
            return (cnt <= h);

        };


        while(l <= r) {
            long long mid = (l + r) / 2;
        
            if(isPos(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;

    }
};