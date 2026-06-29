// Last updated: 6/29/2026, 10:19:49 AM
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for(auto num : nums1) {
            mp1[num]++;
        }
        for(auto num : nums2) {
            mp2[num]++;
        }

        for (auto it = mp1.begin(); it != mp1.end(); ) {
            int key = it->first;
            int val = it->second;

            if (mp2.count(key) && mp2[key] == val) {
                mp2.erase(key);
                it = mp1.erase(it);   // erase safely
            } 
            else {
                if (val == 1 && !mp2.count(key)) return -1;
                ++it;
            }
        }

        int cnt = 0;
        for(auto &[key, val] : mp1 ) {
            if( (val + mp2[key]) % 2 == 1) return -1; 
            int temp = mp2[key] + val;
            temp /= 2;
            cnt += max(0, val - temp);
        }
        
        for(auto &[key, val] : mp2 ) {
            if( (val + mp1[key]) % 2 == 1) return -1; 
        }
        return cnt;
    }
};