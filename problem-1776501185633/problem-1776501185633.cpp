// Last updated: 4/18/2026, 2:03:05 PM
1class Solution {
2public:
3    vector<int> minOperations(vector<int>& nums) {
4        vector<int> isPalid;
5
6        int maxElem = *max_element(nums.begin(), nums.end());
7        int bits = ceil(log2(maxElem + 1));
8        int last = (1 << bits) - 1;
9        
10        isPalid.push_back(0);
11        isPalid.push_back(1);
12
13        auto isPalindrome = [&](int x) -> bool {
14            int original = x, rev = 0;
15
16            while (x > 0) {
17                rev = (rev << 1) | (x & 1);
18                x = x >> 1;
19            }
20
21            return original == rev;
22        };
23        
24        for(int i = 2; i <= last; i++) {
25            if(isPalindrome(i)) {
26                isPalid.push_back(i);
27            }
28        }
29
30        vector<int> res;
31
32        for(auto &n : nums) {
33            
34            int idx = lower_bound(isPalid.begin(), isPalid.end(), n) - isPalid.begin();
35            int diff = min(abs(isPalid[idx - 1] - n), abs(n - isPalid[idx]));
36            res.push_back(diff);
37
38        }
39
40        return res;
41    }
42};