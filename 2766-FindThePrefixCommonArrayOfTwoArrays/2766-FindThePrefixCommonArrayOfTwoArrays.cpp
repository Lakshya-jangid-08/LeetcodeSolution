// Last updated: 6/29/2026, 10:20:56 AM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> res(n);
        for(int idx = 0; idx < n; idx++) {
            
            int cnt = 0;
            for(int i = 0; i <= idx; i++) {
                for(int j = 0; j <= idx; j++) {
                    if(A[i] == B[j]) cnt++;
                }
            }

            res[idx] = cnt;
        }
        return res;
    }
};