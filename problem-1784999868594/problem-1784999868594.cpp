// Last updated: 7/25/2026, 10:47:48 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int m = nums2.size();
5        vector<int> greaterElem(m, -1);
6
7        unordered_map<int, int> mp;
8
9        for(int i = 0; i < nums1.size(); i++) {
10            for(int j = 0; j < m; j++) {
11                if(nums1[i] == nums2[j]) {
12                    mp[i] = j;
13                }
14            }
15        }
16
17        stack<int> s;
18        int i = m - 1;
19        while(i >= 0) {
20            while(!s.empty() && s.top() <= nums2[i]) s.pop();
21            if(!s.empty()) greaterElem[i] = s.top();
22            s.push(nums2[i]);
23            i--;
24        }
25
26        vector<int> res;
27        for(int i = 0; i < nums1.size(); i++) {
28            int idx = mp[i];
29            res.push_back(greaterElem[idx]);
30        }
31        return res;
32    }
33};