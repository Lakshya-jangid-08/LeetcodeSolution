// Last updated: 8/23/2026, 2:26:40 AM
1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        // overlap ones end with another start
5        // sort by start;
6        sort(intervals.begin(), intervals.end(),[](auto & a, auto &b) {
7            return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
8        });
9
10        int start = intervals[0][0];    
11        int end = intervals[0][1];
12
13        vector<vector<int>> res;
14        for(int i = 1; i < intervals.size(); i++) {
15            int currSt = intervals[i][0], currEnd = intervals[i][1];
16
17            if(end >= currSt) {
18                end = max(end, currEnd);
19            } else {
20                res.push_back({start, end});
21                start = currSt;
22                end = currEnd;
23            }
24        }
25        res.push_back({start, end});
26        return res;
27    }
28};