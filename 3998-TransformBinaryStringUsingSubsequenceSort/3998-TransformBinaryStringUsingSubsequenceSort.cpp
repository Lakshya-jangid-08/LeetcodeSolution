// Last updated: 7/25/2026, 9:07:20 PM
1class Solution {
2public:
3    vector<bool> transformStr(string s, vector<string>& strs) {
4        int m = strs.size();
5        int n = s.size();
6
7        vector<bool> ans;
8        for(int i = 0;i<m;i++){
9            int cn0 = 0;
10            int cn1 = 0;
11            int cn2 = 0;
12            for(int j = 0;j<n;j++){
13                if(strs[i][j] == '0') cn0++;
14                else if(strs[i][j] == '1') cn1++;
15                else cn2++;
16                
17                if(s[j] == '0'){
18                    if(cn0 == 0){
19                        if(cn2 == 0){
20                            ans.push_back(false);
21                            break;
22                        }
23                        else cn2--;
24                    }
25                    else cn0--;
26                }
27            }
28            
29            if(ans.size() != i+1){
30                if(cn0 > 0) ans.push_back(false);
31                else ans.push_back(true);
32            }
33        }
34
35        return ans;
36    }
37};