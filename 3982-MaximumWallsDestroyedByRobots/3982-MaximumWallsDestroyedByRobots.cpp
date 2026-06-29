// Last updated: 6/29/2026, 10:20:14 AM
class Solution {
    int dp[100001][3];
    int countInRange(vector<int>& v, int l, int r) {
        auto left = lower_bound(v.begin(), v.end(), l);
        auto right = upper_bound(v.begin(), v.end(), r);

        return right - left;
    }

    int solve(int idx, int dir, vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        if(idx == robots.size()) return 0;

        if(dp[idx][dir] != -1) return dp[idx][dir];

        // 
        int pos = robots[idx];
        int dis = distance[idx];
        if(dir == 2) {
            // distroy left walls;
            // cout << "dir : " << dir << "  idx :"<< idx << "  l: " << pos - dis << "  r: " << pos << "  cnt: "<<countInRange(walls, pos - dis, pos);
            int dl = countInRange(walls, pos - dis, pos) + solve(idx + 1, 0, robots, distance, walls);
            // distroy right walls;
            int next = (idx + 1 == robots.size() ? 1e9 : robots[idx + 1]);
            int dr = countInRange(walls, pos, min(pos + dis, next - 1)) + solve(idx + 1, 1, robots, distance, walls);

            return dp[idx][dir] =  max(dr, dl);

        } else if (dir == 1) {
            // distroy right walls;
            
            int next = (idx + 1 == robots.size() ? 1e9 : robots[idx + 1]);
            int dr = countInRange(walls, pos ,min(pos + dis, next - 1)) + solve(idx + 1, 1, robots, distance, walls);
            // distroy left walls;
            int prev = (idx == 0 ? -1e9 : robots[idx - 1] + distance[idx - 1] + 1);
            int dl = countInRange(walls, max(min(prev, pos), pos - dis), pos ) + solve(idx + 1, 0, robots, distance, walls);
            return dp[idx][dir] =  max(dr, dl);
        } else {
            // choose Left means dir == 0
            int next = (idx + 1 == robots.size() ? 1e9 : robots[idx + 1]);
            int dr = countInRange(walls, pos ,min(pos + dis, next - 1)) + solve(idx + 1, 1, robots, distance, walls);

            int prev = (idx == 0 ? -1e9 : robots[idx - 1]);
            int dl = countInRange(walls, max(prev + 1, pos - dis), pos ) + solve(idx + 1, 0, robots, distance, walls);

            return dp[idx][dir] =  max(dr, dl);
        }
        return -1;
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        sort(walls.begin(), walls.end());
        vector<pair<int,int>> v;

        for(int i = 0; i < robots.size(); i++) {
            v.push_back({robots[i], distance[i]});
        }

        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < v.size(); i++) {
            robots[i] = v[i].first;
            distance[i] = v[i].second;
        }
        // idx, left/right/null 
        
        return solve(0, 2, robots, distance, walls);

    }
};