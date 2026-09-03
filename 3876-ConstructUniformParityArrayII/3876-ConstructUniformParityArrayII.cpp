// Last updated: 9/3/2026, 11:09:26 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums) {
4        //  even - odd => odd
5        // odd - oddd => even
6
7        int n = nums.size();
8        int minodd = 1e8;
9        int mineven = 1e8;
10        // if all are even;
11        for(int i = 0; i < n; i++) {
12            if(nums[i] % 2 == 1)
13                minodd = min(minodd, nums[i]);
14            else 
15                mineven = min(mineven, nums[i]);
16        }
17
18        // if all oddd ban jaye
19        bool ans = true;
20        for(int i = 0; i < n; i++) {
21            if(nums[i] % 2 == 1) {
22                continue;
23            } else {
24                if(nums[i] - minodd >= 1) continue;
25                else {
26                    ans = false;
27                    break;
28                }
29            }
30        }
31        bool res = true;
32        for(int i = 0; i < n; i++) {
33            if(nums[i] % 2 == 0) {
34                continue;
35            } else {
36                if(nums[i] - minodd >= 1) continue;
37                else {
38                    res = false;
39                    break;
40                }
41            }
42        }
43        return res | ans;
44    }
45};