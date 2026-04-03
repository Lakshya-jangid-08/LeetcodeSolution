// Last updated: 4/4/2026, 12:55:26 am
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        priority_queue< pair<double, int> > pq;
5        int id = 0;
6        for(auto cord : points) {
7            int x = cord[0], y = cord[1];
8            double dis = sqrt(1LL * x*x + 1LL * y*y);
9            pq.push({dis, id});
10        
11            if(pq.size() > k) {
12                pq.pop();
13            }
14            id++;
15        }
16        vector<vector<int>> res;
17        while(!pq.empty()) {
18            int idx = pq.top().second;
19            res.push_back(points[idx]);
20            pq.pop();
21        }
22
23        return res;
24    }
25};