// Last updated: 9/6/2026, 9:11:41 PM
1class unionSet {
2 public:
3    vector<int> par, size;
4    unionSet(int n) : par(n), size(n, 1) {
5        iota(par.begin(), par.end(), 0);
6    }
7
8    int findPar(int x) {
9        if(x == par[x]) return x;
10        return par[x] = findPar(par[x]);
11    }
12
13    void join(int u, int v) {
14        int pu = findPar(u), pv = findPar(v);
15
16        if(pu == pv) return;
17
18        if(size[pu] < size[pv]) {
19            size[pv] += size[pu];
20            par[pu] = pv;
21        } else {
22            size[pu] += size[pv];
23            par[pv] = pu;
24        }
25    }
26
27};
28class Solution {
29public:
30    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
31        int n = accounts.size();
32
33        unordered_map< string, int> mailMp;
34        
35        unionSet dsu(n + 1);
36
37        int uid = 0;
38        for(auto &acc : accounts) {
39            for(int i = 1; i < acc.size(); i++) {
40                if(mailMp.count(acc[i]) == 0) {
41                    mailMp[acc[i]] = uid;
42                }
43                int &mid = mailMp[acc[i]];
44                dsu.join(uid, mid);
45            }
46            uid++;
47        }
48
49        vector<vector<string>> res;
50        vector<string> mp[n];
51        
52        for(auto &[mail, id] : mailMp) {
53            int parent = dsu.findPar(id);
54            mp[parent].push_back(mail);
55        }
56
57
58        for(int i = 0; i < n; i++) {
59            if(mp[i].size() == 0) continue;
60            res.push_back({accounts[i][0]});
61
62            sort(mp[i].begin(), mp[i].end());
63            for(auto &v : mp[i]) res.back().push_back(v);
64        }
65        return res;
66    }
67};