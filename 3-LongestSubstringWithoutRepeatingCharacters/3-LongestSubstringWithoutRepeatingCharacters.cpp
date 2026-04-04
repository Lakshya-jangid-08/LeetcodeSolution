// Last updated: 4/4/2026, 10:29:00 am
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
//         if(s.size()==0)return 0;
//         int ans=0, count=0;
//         int left=0, right=0;
//         int freq[128]={0};

//         while(right<s.size())
//         {
//             if(freq[s[right]]==1)
//             {
//                 freq[s[left]]--;
//                 left++;
//                 count--;
//             }
//             else
//             {
//                 freq[s[right]]++;
//                 right++;
//                 count++;
//             } 
//             ans = max(count,ans);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1); // last seen index
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            if (last[s[r]] >= l) {
                l = last[s[r]] + 1; // shrink window
            }
            last[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
