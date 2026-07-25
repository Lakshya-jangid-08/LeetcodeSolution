// Last updated: 7/25/2026, 10:56:13 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int m = nums2.size();
5        vector<int> greaterElem(m, -1);
6
7        unordered_map<int, int> mp;
8
9
10        stack<int> s;
11        int i = m - 1;
12        while(i >= 0) {
13            while(!s.empty() && s.top() <= nums2[i]) s.pop();
14            if(!s.empty()) greaterElem[i] = s.top();
15            s.push(nums2[i]);
16            i--;
17        }
18
19        for(int i = 0; i < m; i++) {
20            mp[nums2[i]] = greaterElem[i]; 
21        }
22        vector<int> res;
23        for(const auto & v : nums1) {
24            const int &v2 = mp[v];
25            res.push_back(v2);
26        }
27        return res;
28    }
29};