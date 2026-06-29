// Last updated: 6/29/2026, 10:22:04 AM
class Solution {  

public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> currXor;
        unordered_set<int> prev;
        unordered_set<int> res;
        prev.insert(arr[n - 1]);
        res.insert(arr[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            res.insert(arr[i]);
            currXor.insert(arr[i]);
            for(auto x : prev) {
                currXor.insert((arr[i] | x));
                res.insert(arr[i] | x);
            }
            prev = currXor;
            currXor.clear();
        }


        return res.size();
    }
};