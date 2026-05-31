// Last updated: 5/31/2026, 3:31:03 PM
1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        sort(asteroids.begin(), asteroids.end());
5        long long m = mass;
6        for(int i = 0; i < asteroids.size(); i++) {
7            if(1LL * asteroids[i] > m) return false;
8            m += 1LL * asteroids[i];
9        }
10
11        return true;
12    }
13};