// Last updated: 6/29/2026, 10:21:36 AM
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // tasks => actual(i th tasks takes energy), minimum (initial energy required)
        sort(tasks.begin(), tasks.end(), [](const auto &a, const auto &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int curr = 0, need = 0;
        for(int i = 0; i < tasks.size(); i++) {
            if(curr < tasks[i][1]) {
                need += tasks[i][1] - curr;
                curr = tasks[i][1];
            }
            curr -= tasks[i][0];
        }
        return need;
    }
};