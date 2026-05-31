// Last updated: 5/31/2026, 3:38:33 PM
1class Solution {
2public:
3    bool asteroidsDestroyed(long long mass, vector<int>& ast) {
4        int n = ast.size();
5        int maxi = *max_element(ast.begin(), ast.end());
6        int mini = *min_element(ast.begin(), ast.end());
7
8        vector<int> cnt(maxi + 1, 0);
9
10        for(int i = 0; i < n; i++) {
11            cnt[ast[i]]++;
12        }
13
14        for(int i = mini; i <= maxi; i++) {
15            if(maxi <= mass) return true; 
16            if(cnt[i] == 0) continue;
17            if(i > mass) return false;
18
19            mass += 1LL * cnt[i] * i;
20
21        }
22        
23        return true;
24    }
25};