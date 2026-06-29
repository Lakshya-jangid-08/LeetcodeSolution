// Last updated: 6/29/2026, 10:21:27 AM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(res != arr[i]) res += 1;
        }
        return res;
    }
};