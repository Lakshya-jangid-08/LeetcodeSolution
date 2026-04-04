// Last updated: 4/4/2026, 11:11:32 pm
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        bool contains_ones = false;   
5        for(auto &x : nums) {
6            if(x == 1) {
7                contains_ones = true;
8            }
9            if(x <= 0 || x > nums.size()) x = 1;
10        }
11        if(!contains_ones) return 1;
12
13        for(int i = 0; i < nums.size(); i++) {
14            // number present hai ? 
15            int val = abs(nums[i]);
16            // number 1 to N hai toh joh number present hai
17            // uska nums[val - 1] neg kr deta hu 
18            // mtlb present haii 
19            // Agar > 0 nhi hai mtlb woh idx kbhi process nhi huwa
20            // mtlb woh missing hai
21            nums[val - 1] = abs(nums[val - 1]) * -1; 
22        }
23
24        for(int i = 0; i < nums.size(); i++) {
25            if(nums[i] > 0) return i + 1;
26        }
27        return nums.size() + 1;
28    }
29};