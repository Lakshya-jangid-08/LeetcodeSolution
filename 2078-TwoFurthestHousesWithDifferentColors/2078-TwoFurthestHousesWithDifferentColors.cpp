// Last updated: 4/28/2026, 7:41:13 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int ans = 0;
6        int i=0; int j=n-1;
7        while(colors[i]==colors[j]) j--;
8        ans = max(ans,j-i);
9
10        j = n-1;
11        while(colors[i]==colors[j]) i++;
12        ans = max(ans,j-i);
13
14        return ans;
15    }
16};