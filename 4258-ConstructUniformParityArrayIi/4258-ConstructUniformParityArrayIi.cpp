// Last updated: 6/29/2026, 10:19:45 AM
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        //  even - odd => odd
        // odd - oddd => even

        int n = nums.size();
        int minodd = 1e8;
        int mineven = 1e8;
        // if all are even;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1)
                minodd = min(minodd, nums[i]);
            else 
                mineven = min(mineven, nums[i]);
        }

        // if all oddd ban jaye
        bool ans = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) {
                continue;
            } else {
                if(nums[i] - minodd >= 1) continue;
                else {
                    ans = false;
                    break;
                }
            }
        }
        bool res = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                continue;
            } else {
                if(nums[i] - minodd >= 1) continue;
                else {
                    res = false;
                    break;
                }
            }
        }
        return res | ans;
    }
};