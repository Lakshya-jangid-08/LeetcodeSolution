// Last updated: 8/23/2026, 11:25:19 AM
1class Solution {
2public:
3    bool overlap(int s1, int e1, int s2, int e2) {
4        if(e1 < s2 || e2 < s1) return false;
5        return true;
6    }
7
8    vector<vector<int>> merge(vector<vector<int>>& intervals) {
9        // overlap ones end with another start
10        // sort by start;
11        sort(intervals.begin(), intervals.end(),[](auto & a, auto &b) {
12            return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
13        });
14
15        int start = intervals[0][0];    
16        int end = intervals[0][1];
17
18        vector<vector<int>> res;
19        for(int i = 1; i < intervals.size(); i++) {
20            int currSt = intervals[i][0], currEnd = intervals[i][1];
21
22            if(end >= currSt) {
23                end = max(end, currEnd);
24            } else {
25                res.push_back({start, end});
26                start = currSt;
27                end = currEnd;
28            }
29        }
30        res.push_back({start, end});
31        return res;
32    }
33
34    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
35        
36        int n = firstList.size(), m = secondList.size();
37
38        vector<vector<int>> intervals;
39
40        for(int i = 0; i < n; i++) {
41            int f_s = firstList[i][0], f_e = firstList[i][1];
42            for(int j = 0; j < m; j++) {
43                int s_s = secondList[j][0], s_e = secondList[j][1];
44                
45                int s = max(s_s, f_s);
46                int e = min(s_e, f_e);
47
48                if(s <= e) {
49                    intervals.push_back({s, e});
50                }
51            }
52        }
53
54        if(intervals.empty()) return {};
55        return merge(intervals);
56    }
57};