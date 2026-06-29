// Last updated: 6/29/2026, 10:19:48 AM
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int l1 = -1;
        int l2 = -1;
        int i = 0;
        int ans = 1e9;
        for(auto n : nums) {
            if(n == 1) {
                l1 = i;
                ans = (l2 != -1 ? min(ans, abs(l1- l2)) : ans);
            } else if( n == 2) {
                l2 = i;
                ans = (l1 != -1 ? min(ans, abs(l1 - l2)) : ans);
            }
            i++;
        }
        return (ans != 1e9 ? ans : -1);
        
    }
};