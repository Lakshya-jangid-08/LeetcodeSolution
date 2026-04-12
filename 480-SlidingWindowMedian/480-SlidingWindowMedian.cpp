// Last updated: 12/4/2026, 10:30:04 pm
1class Solution {
2public:
3    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
4        vector<double> res;
5        // store first half [0 ... n/2]
6        set<pair<int, int>, greater<pair<int,int>> > maxset; 
7        
8        // store second half [n/2 .... n]
9        set<pair<int, int>> minset;
10
11        for(int i = 0; i < k; i++) {
12            minset.insert({nums[i], i});
13        }
14
15        for(int i = 0; i < k/2; i++) {
16            auto it = minset.begin(); 
17            maxset.insert(*it);
18            minset.erase(it);
19        }
20        double median = 1.0;
21        if(k % 2)
22            median = minset.begin()->first;
23        else
24            median = (1.0 * maxset.begin()->first + 1.0 * minset.begin()->first) / 2.0;
25        
26        res.push_back(median);
27        int r = k, l = 0;
28
29        while(r < nums.size()) {
30            
31            pair<int,int> add = {nums[r], r};
32            pair<int,int> remove = {nums[l], l};
33            int f = 1;
34            if(maxset.find(remove) != maxset.end()) {
35                maxset.erase(remove);
36                f--;
37            } else {
38                minset.erase(remove);
39            }
40
41            if(f) {
42                maxset.insert(add);
43                auto it = maxset.begin();
44                minset.insert(*it);
45                maxset.erase(it);
46            } else {
47                minset.insert(add);
48                auto it = minset.begin();
49                maxset.insert(*it);
50                minset.erase(it);
51            }
52
53
54            if(k % 2)
55                median = minset.begin()->first;
56            else
57                median = (1.0 * maxset.begin()->first + 1.0 * minset.begin()->first) / 2.0;
58            
59            res.push_back(median);
60            r++; l++;
61        }
62
63        return res;
64    }
65};