// Last updated: 5/21/2026, 12:06:30 PM
1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5
6        vector<int> res(n);
7        for(int idx = 0; idx < n; idx++) {
8            
9            int cnt = 0;
10            for(int i = 0; i <= idx; i++) {
11                for(int j = 0; j <= idx; j++) {
12                    if(A[i] == B[j]) cnt++;
13                }
14            }
15
16            res[idx] = cnt;
17        }
18        return res;
19    }
20};