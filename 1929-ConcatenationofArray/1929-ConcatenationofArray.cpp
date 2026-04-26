// Last updated: 4/26/2026, 1:22:35 PM
1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>res;
6        map<int,int>  freq;
7        for(int i = 0; i < n; i++) freq[nums[i]] = 1;
8        for(int i = 1; i <= n; i++) {
9            if(freq[i] == 0) res.push_back(i);
10        }
11        return res;
12    }
13};