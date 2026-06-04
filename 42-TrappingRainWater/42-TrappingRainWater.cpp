// Last updated: 6/4/2026, 4:51:35 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5        vector<int> left(n,0), right(n,0);
6        left[0] = height[0];
7        for(int i = 1; i < n; i++) {
8            left[i] = max(height[i],left[i-1]);
9        }
10        right[n-1] = height[n-1];
11        for(int i = n-2; i >= 0; i--) {
12            right[i] = max(right[i+1],height[i]);
13        }  
14        int totalTrap = 0;
15
16        for(int i = 0; i < n; i++) {
17            if(height[i] >= min(left[i],right[i]))  continue;
18            totalTrap += min(left[i],right[i]) - height[i];
19        }
20        return totalTrap;
21    }
22};