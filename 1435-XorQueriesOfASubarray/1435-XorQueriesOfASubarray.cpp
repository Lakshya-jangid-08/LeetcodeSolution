// Last updated: 6/29/2026, 10:21:50 AM
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n, 0);

        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = arr[i] ^ prefix[i - 1];
        }

        vector<int> res;

        for(auto q : queries) {
            int l = q[0], r = q[1];
            int prev = (l == 0 ? 0 : prefix[l - 1]);
            res.push_back( prefix[r] ^ prev );
        }
        return res;
    }
};