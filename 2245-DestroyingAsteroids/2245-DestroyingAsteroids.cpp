// Last updated: 6/29/2026, 10:21:08 AM
class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& ast) {
        int n = ast.size();
        int maxi = *max_element(ast.begin(), ast.end());
        int mini = *min_element(ast.begin(), ast.end());

        vector<int> cnt(maxi + 1, 0);

        for(int i = 0; i < n; i++) {
            cnt[ast[i]]++;
        }

        for(int i = mini; i <= maxi; i++) {
            if(maxi <= mass) return true; 
            if(cnt[i] == 0) continue;
            if(i > mass) return false;

            mass += 1LL * cnt[i] * i;

        }
        
        return true;
    }
};