// Last updated: 7/21/2026, 6:51:39 PM
1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
5            return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
6        });
7
8        int n, res;
9        res = n = intervals.size();
10
11        for(int i = 1; i < n; i++) {
12            if(intervals[i - 1][0] <= intervals[i][0] && intervals[i][1] <= intervals[i - 1][1]) {
13                res--;
14                intervals[i] = intervals[i - 1];
15            }
16        }
17        return res;
18    }
19};