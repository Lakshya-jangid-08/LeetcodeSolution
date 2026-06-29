// Last updated: 6/29/2026, 10:21:51 AM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        queue<int> q;
        q.push(start);

        vector<bool> v(n, false);

        while(!q.empty()) {
            int f_elem = q.front(); q.pop();
            
            if(arr[f_elem] == 0) return true;
            if(v[f_elem]) continue;
            v[f_elem] = true; 
            if(f_elem + arr[f_elem] < n) q.push(f_elem + arr[f_elem]);
            if(f_elem - arr[f_elem] >= 0) q.push(f_elem - arr[f_elem]);

        }
        return false;
    }
};