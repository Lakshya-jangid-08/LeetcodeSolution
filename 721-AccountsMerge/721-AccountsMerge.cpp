// Last updated: 9/6/2026, 8:59:15 PM
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
32        int uniqueId = n + 1;
33
34        unordered_map< string, int> mailMp;
35        unordered_map< int, string> ownerMp;
36        int uid = 0;
37        
38        unionSet dsu(1e5);
39
40        for(auto &acc : accounts) {
41            ownerMp[uid] = acc[0];
42            for(int i = 1; i < acc.size(); i++) {
43                if(mailMp.count(acc[i]) == 0) {
44                    mailMp[acc[i]] = uniqueId;
45                    uniqueId += 1;
46                }
47                int &mid = mailMp[acc[i]];
48                dsu.join(uid, mid);
49            }
50            uid++;
51        }
52
53        vector<vector<string>> res;
54        unordered_map<int, vector<string>> mp;
55        
56        for(auto &[mail, id] : mailMp) {
57            int parent = dsu.findPar(id);
58            mp[parent].push_back(mail);
59        }
60
61
62        for(auto &[parent, arr] : mp) {
63            res.push_back({ownerMp[parent]});
64
65            sort(arr.begin(), arr.end());
66            for(auto &v : arr) res.back().push_back(v);
67        }
68        return res;
69    }
70};