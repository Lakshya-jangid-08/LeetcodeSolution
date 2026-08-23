// Last updated: 8/23/2026, 11:14:21 AM
1class Solution {
2public:
3   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
4        int n = intervals.size(), i = 0;
5        vector<vector<int>> res;
6        //case 1: no overlapping case before the merge intervals
7		//compare ending point of intervals to starting point of newInterval
8        while(i < n && intervals[i][1] < newInterval[0]){
9            res.push_back(intervals[i]);
10            i++;
11        }                           
12		//case 2: overlapping case and merging of intervals
13        while(i < n && newInterval[1] >= intervals[i][0]){
14            newInterval[0] = min(newInterval[0], intervals[i][0]);
15            newInterval[1] = max(newInterval[1], intervals[i][1]);
16            i++;
17        }
18        res.push_back(newInterval);
19        // case 3: no overlapping of intervals after newinterval being merged
20        while(i < n){
21            res.push_back(intervals[i]);
22            i++;
23        }
24        return res;
25    }
26};