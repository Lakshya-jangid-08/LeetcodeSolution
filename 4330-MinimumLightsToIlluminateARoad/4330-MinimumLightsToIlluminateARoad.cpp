// Last updated: 6/29/2026, 10:19:09 AM
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);

        for(int i = 0; i < n; i++) {
            if(lights[i] == 0) continue;
            int l = max(0, i - lights[i]), r = min(n-1,i + lights[i]);
            diff[l]++; diff[r + 1]--;
        }
        int cnt = 0, sum = 0, res = 0;
        for(int i = 0; i < n; i++) {
            sum += diff[i];
            if(sum == 0) {
                cnt += 1;
            } else {
                res += (cnt + 2) / 3;
                cnt = 0;
            }
        }
        if(cnt > 0) {
            res += (cnt + 2) / 3;
        }
        return res;
    }
};