// Last updated: 6/29/2026, 10:20:29 AM
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;

        for(auto &q : queries) {
            int val = nums[q];
            vector<int> & temp = mp[val];

            if(temp.size() == 1) {
                res.push_back(-1);
                continue;
            }

            auto it = lower_bound(temp.begin(), temp.end(), q); // >= find
            int idx = it - temp.begin();
            int dist = 1e9;

            int m = temp.size();

            int prevIdx = temp[(idx - 1 + m) % m];
            int nextIdx = temp[(idx + 1) % m];

            int d1 = abs(q - prevIdx);
            int d2 = abs(q - nextIdx);

            dist = min(dist, min(d1, n - d1));
            dist = min(dist, min(d2, n - d2));

            res.push_back(dist);

        }

        return res;

    }
};