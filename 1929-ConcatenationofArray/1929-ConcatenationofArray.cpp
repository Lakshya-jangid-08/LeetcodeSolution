// Last updated: 4/26/2026, 1:22:02 PM
1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        int duplicate = 0;
5        int original = 0;
6        int n = nums.size();
7        vector<int> freq(n+1, 0);
8        for(int i = 0; i < n; i++){
9            freq[nums[i]]++;
10        }
11        for(int i = 1; i <= n; i++){
12            if(freq[i] == 2) duplicate = i;
13            if(freq[i] == 0) original = i;
14        }
15        return {duplicate, original};
16    }
17};