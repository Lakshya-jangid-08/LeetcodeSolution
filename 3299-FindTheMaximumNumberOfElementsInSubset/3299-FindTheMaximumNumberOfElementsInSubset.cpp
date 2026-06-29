// Last updated: 6/29/2026, 10:20:43 AM
const int LIMIT = 31'623;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        bitset<LIMIT> freq1, freq2, sqSet;
        int cnt = 0, mxv = 0, mnv = LIMIT;
        for(int v : nums) {
            if(v == 1) cnt += 1;
            else if(v < LIMIT) {
                if(!freq1[v]) {
                    freq1[v] = 1;
                } else {
                    freq2[v] = 1;
                    if(v == 1) continue;
                    mxv = max(mxv, v);
                    mnv = min(mnv, v);
                }
            } else {
                int r = sqrt(v);
                if(r * r == v) sqSet[r] = 1;
            }
        }

        int res = (cnt % 2) ? cnt : cnt - 1;
        res = max(res, 1);

        while(mnv <= mxv) {
            int x = mnv;
            int curr = 0;
            while(x < LIMIT) {
                if(freq2[x]) {
                    curr += 2;
                    if(x * x >= LIMIT) {
                        curr += sqSet[x] ? 1 : -1;
                        break;
                    }
                } else if(freq1[x]) {
                    curr += 1;
                    break;
                } else if(!freq1[x]) {
                    curr -= 1;
                    break;
                }
                x = x * x;
            } 
            res = max(res, curr);
            mnv += 1;
        }
        return res;
    }
};