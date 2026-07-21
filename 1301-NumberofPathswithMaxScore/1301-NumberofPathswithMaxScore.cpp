// Last updated: 7/21/2026, 10:53:53 PM
1class Solution {
2public:
3    int MOD = 1e9 + 7;
4    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
5        int n = s.length();
6        vector<int> prefixSum(n + 1, 0);
7        vector<int> numUpto(n + 1, 0);
8        vector<int> nonZero(n + 1, 0);
9        
10        for(int i = 0; i < n; i++) {
11            prefixSum[i + 1] = prefixSum[i] + (s[i] - '0');
12            nonZero[i + 1] = nonZero[i];
13            numUpto[i + 1] = numUpto[i];
14            if(s[i] == '0') continue;
15            numUpto[i + 1] = (1LL * numUpto[i]  * 10 + (s[i] - '0') ) % MOD; 
16            nonZero[i + 1] += 1;
17        } 
18
19        vector<int> pow10(n + 1, 0);
20        pow10[0] = 1;
21        for(int i = 1; i <= n; i++) {
22            pow10[i] = (10LL * pow10[i - 1]) % MOD;
23        }
24
25        vector<int> res;
26        for(auto &q : queries) {
27            int l = q[0] + 1, r = q[1] + 1;
28            int currSum = prefixSum[r] - prefixSum[l - 1];
29            int k = nonZero[r] - nonZero[l - 1];
30
31
32            int qNum = (1LL * numUpto[r] - (1LL * pow10[k] * numUpto[l - 1] % MOD) + MOD) % MOD;
33        // cout << k << " " << currSum << " " << qNum << endl;;
34            qNum = (1LL * qNum * currSum) % MOD;
35            res.push_back(qNum);
36        }
37        return res;
38    }
39};