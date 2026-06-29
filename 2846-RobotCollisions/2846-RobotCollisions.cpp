// Last updated: 6/29/2026, 10:20:54 AM
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](const int l, const int r) {
            return positions[l] < positions[r];
        });

        stack<int> s;

        for(int i = 0; i < n; i++) {
            int currIdx = idx[i];
            int currH = healths[currIdx];
            int currD = directions[currIdx];
            // collision only between R & L;  x => LR, RR, LL 
            if(currD == 'R') {
                s.push(currIdx);
            } else {
                while(!s.empty() && directions[s.top()] == 'R' && healths[s.top()] < currH) {
                    int tempIdx = s.top();
                    healths[tempIdx] = 0;
                    healths[currIdx]--;
                    currH--;
                    s.pop();
                }
                if(currH == 0) continue;
                if(s.empty() || directions[s.top()] == 'L') {
                    s.push(currIdx);
                }
                else if(!s.empty() && currH == healths[s.top()] && directions[s.top()] == 'R') {
                    int tempIdx = s.top();
                    healths[currIdx] = 0;
                    healths[tempIdx] = 0;
                    s.pop();
                }
                else {
                    int tempIdx = s.top();
                    healths[tempIdx]--;
                    healths[currIdx] = 0; 
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) res.push_back(healths[i]);
        }
        return res;
    }
};