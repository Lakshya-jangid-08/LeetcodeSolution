// Last updated: 6/29/2026, 10:23:16 AM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int elem = INT_MIN;

        for(auto n : nums) {
            if(n != elem) {
                if(cnt == 0) {
                    cnt = 1;
                    elem = n;
                } else {
                    cnt--;
                }   
            } else {
                cnt++;
            }
        }
        return elem;
    }
};