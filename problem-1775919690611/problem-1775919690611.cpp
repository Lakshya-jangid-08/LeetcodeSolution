// Last updated: 11/4/2026, 8:31:30 pm
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        int n = 1e5 + 10;
5        vector<bool> prime(n, false);
6        prime[0] = true;
7        if(n > 1) prime[1] = true;
8        for(int i = 2; i * i < n ; i++) {
9            if(!prime[i]) {
10                for(int j = i * 2; j < n; j += i) {
11                    prime[j] = true;
12                }
13            }
14        }
15        int ops = 0;
16        int len = nums.size();
17
18        vector<int> vals;
19
20        for(int i = 0; i < n; i++) {
21            if(prime[i] == true) continue;
22            vals.push_back(i);
23        }
24        for(int i = 0; i < len; i++) {
25            if(i%2 == 0) {
26                // non prime
27                if(prime[nums[i]]) {
28                    auto it = lower_bound(vals.begin(), vals.end(), nums[i]);
29                    int greater = -1e9;
30                    if(it != vals.end()) {
31                        greater = *it;
32                    }
33
34                    ops += abs(greater - nums[i]);
35                }
36            } else {
37                if(!prime[nums[i]]) {
38                    int curr = nums[i];
39                    while(!prime[curr]) {
40                        curr++;
41                    }
42                    ops += abs(curr - nums[i]);
43                }
44            }
45        }
46        return ops;
47    }
48};