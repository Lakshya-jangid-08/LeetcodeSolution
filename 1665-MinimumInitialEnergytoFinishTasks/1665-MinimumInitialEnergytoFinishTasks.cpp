// Last updated: 5/12/2026, 7:59:26 AM
1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& tasks) {
4        // tasks => actual(i th tasks takes energy), minimum (initial energy required)
5        sort(tasks.begin(), tasks.end(), [](const auto &a, const auto &b) {
6            return (a[1] - a[0]) > (b[1] - b[0]);
7        });
8        int curr = 0, need = 0;
9        for(int i = 0; i < tasks.size(); i++) {
10            if(curr >= tasks[i][1]) {
11                curr -= tasks[i][0];
12            } else {
13                need += tasks[i][1] - curr;
14                curr = tasks[i][1];
15                curr -= tasks[i][0];
16            }
17        }
18        return need;
19    }
20};