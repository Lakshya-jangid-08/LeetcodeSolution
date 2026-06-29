// Last updated: 6/29/2026, 10:21:59 AM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> idxmp;
        idxmp['b'] = 0;
        idxmp['a'] = 1;
        idxmp['l'] = 2;
        idxmp['o'] = 3;
        idxmp['n'] = 4;
        vector<int> count(5, 0);
        for(auto &c : text) {
            if(idxmp.count(c) == 0) continue;
            count[idxmp[c]]++;
        }

        count[3] /= 2;
        count[2] /= 2;
        return *min_element(count.begin(), count.end());
    }
};