// Last updated: 6/29/2026, 10:22:02 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, int> > pq;
        int id = 0;
        for(auto cord : points) {
            int x = cord[0], y = cord[1];
            int dis = x*x + y*y;
            pq.push({dis, id});
        
            if(pq.size() > k) {
                pq.pop();
            }
            id++;
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            int idx = pq.top().second;
            res.push_back(points[idx]);
            pq.pop();
        }

        return res;
    }
};