// Last updated: 7/28/2026, 4:41:36 PM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int m = nums.size();
5        vector<int> ge(m, -1);
6        stack<int> s;
7        int i = m - 1;
8        while(i >= 0) {
9            while(!s.empty() && s.top() <= nums[i]) s.pop();
10            if(!s.empty()) ge[i] = s.top();
11            s.push(nums[i]);
12            i--;
13        }
14        i = m - 1;
15        while(i >= 0) {
16            while(!s.empty() && s.top() <= nums[i]) s.pop();
17            if(!s.empty()) ge[i] = s.top();
18            s.push(nums[i]);
19            i--;
20        }
21
22
23        return ge;
24    }
25};