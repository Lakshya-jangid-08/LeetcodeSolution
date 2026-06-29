// Last updated: 6/29/2026, 10:19:54 AM
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        auto isSorted = [](string &s) -> bool {
            char prev = 'a';
            for(auto &c : s) {
                if(c < prev) return false;
                prev = c;
            }
            return true;
        };

        if(isSorted(s)) return 0;
        if(n == 2) return -1; 

        auto findOccurrence = [&]() -> pair<int,int> {
            int idx1 = -1, idx2 = -1;
            char minElem = 'z', maxElem = 'a';

            for(int i = 0; i < n; i++) {
                if(s[i] >= maxElem) {
                    maxElem = s[i];
                    idx2 = i;
                }
                if(s[i] < minElem) {
                    minElem = s[i];
                    idx1 = i;
                }
            }
            return {idx1, idx2};
        };

        auto [idx1, idx2] = findOccurrence();

        // CASE 1 : Dono element first at last and last at first pe ho -> 3
        if(idx1 == n-1 && idx2 == 0) return 3;
    
        // CASE 2 : pahala element shi position pe hai -> 1
        //  && 
        // CASE 3 : last element shi position pe hai -> 1
        if(idx1 == 0 || idx2 == n - 1) return 1;
        
        // CASE 4 : dono element alg alg middle jagah pe ho, swaps need -> 2
        if(idx1 < n-1 || idx2 > 0) return 2;
        
        return -1;
    }
};