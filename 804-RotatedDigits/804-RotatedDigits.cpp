// Last updated: 6/29/2026, 10:22:15 AM
class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        auto isPoss = [&](int val) -> bool {
            int changed = false;
            while(val > 0) {
                int lastDig = val % 10;
                if(lastDig == 3 || lastDig == 4 || lastDig == 7) return false;

                if(lastDig == 9 || lastDig == 6 || lastDig == 5 || lastDig == 2) changed =  true;

                val /= 10; 
            }
            return changed;
        };

        for(int i = 1; i <= n; i++) {
            ans += (isPoss(i) ? 1 : 0);
        }
        return ans;
    }
};