// Last updated: 7/21/2026, 6:49:01 PM
1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
5            return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
6        });
7
8        int n = intervals.size();
9        int res = n;
10
11        for(int i = 1; i < n; i++) {
12            int prevS = intervals[i - 1][0];
13            int prevE = intervals[i - 1][1];
14            int currS = intervals[i][0];
15            int currE = intervals[i][1];
16            if(prevS <= currS && currE <= prevE) {
17                res--;
18                intervals[i] = intervals[i - 1];
19            }
20        }
21        return res;
22    }
23};