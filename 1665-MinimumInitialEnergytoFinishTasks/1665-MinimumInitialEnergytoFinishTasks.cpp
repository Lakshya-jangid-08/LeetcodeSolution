// Last updated: 5/12/2026, 8:03:13 AM
1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& tasks) {
4        // tasks => actual(i th tasks takes energy), minimum (initial energy required)
5        sort(tasks.begin(), tasks.end(), [](const auto &a, const auto &b) {
6            return (a[1] - a[0]) > (b[1] - b[0]);
7        });
8        int curr = 0, need = 0;
9        for(int i = 0; i < tasks.size(); i++) {
10            if(curr < tasks[i][1]) {
11                need += tasks[i][1] - curr;
12                curr = tasks[i][1];
13            }
14            curr -= tasks[i][0];
15        }
16        return need;
17    }
18};