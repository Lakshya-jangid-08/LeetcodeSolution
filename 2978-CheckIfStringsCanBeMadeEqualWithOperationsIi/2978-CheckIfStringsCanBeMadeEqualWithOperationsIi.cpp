// Last updated: 6/29/2026, 10:20:52 AM
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};
        // odd - odd => even

        for(int i = 0; i < s1.length(); i++) {
            if(i & 1) {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            } else {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0) return false;
            if(odd[i] != 0) return false;
        }

        return true;

    }
};