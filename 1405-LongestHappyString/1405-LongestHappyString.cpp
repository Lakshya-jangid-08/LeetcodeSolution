// Last updated: 8/15/2026, 12:43:37 AM
1class Solution {
2
3public:
4    string longestDiverseString(int a, int b, int c) {
5        
6        priority_queue<pair<int, char>> pq;
7
8        if(a > 0) pq.push({a, 'a'});
9        if(b > 0) pq.push({b, 'b'});
10        if(c > 0) pq.push({c, 'c'});
11        string res = "";
12        while(!pq.empty()) {  
13            int n = res.length(); 
14            auto top_pair = pq.top(); pq.pop();
15
16            if(n >= 2 && res[n - 1] == res[n - 2] && res[n - 1] == top_pair.second) {
17                    if(pq.empty()) break;
18                    auto secondTop = pq.top(); pq.pop();
19                    if(secondTop.first == 0) break;
20                    res.push_back(secondTop.second);
21                    secondTop.first--;
22                    pq.push(secondTop);
23                    pq.push(top_pair);
24            } else {
25                if(top_pair.first == 0) break;
26                res.push_back(top_pair.second);
27                top_pair.first--;
28                pq.push(top_pair);
29            }
30        }
31        return res;
32    }
33};