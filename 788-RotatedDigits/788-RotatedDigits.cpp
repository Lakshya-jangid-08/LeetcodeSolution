// Last updated: 5/2/2026, 2:18:01 PM
1class Solution {
2public:
3    int rotatedDigits(int n) {
4        int ans = 0;
5
6        auto isPoss = [&](int val) -> bool {
7            int changed = false;
8            while(val > 0) {
9                int lastDig = val % 10;
10                if(lastDig == 3 || lastDig == 4 || lastDig == 7) return false;
11
12                if(lastDig == 9 || lastDig == 6 || lastDig == 5 || lastDig == 2) changed =  true;
13
14                val /= 10; 
15            }
16            return changed;
17        };
18
19        for(int i = 1; i <= n; i++) {
20            ans += (isPoss(i) ? 1 : 0);
21        }
22        return ans;
23    }
24};