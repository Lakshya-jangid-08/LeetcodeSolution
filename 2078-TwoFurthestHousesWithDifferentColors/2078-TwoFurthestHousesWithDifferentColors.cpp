// Last updated: 4/20/2026, 9:54:02 AM
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int i=0; int j=n-1;
        while(colors[i]==colors[j]) j--;
        ans = max(ans,j-i);

        j = n-1;
        while(colors[i]==colors[j]) i++;
        ans = max(ans,j-i);

        return ans;
    }
};