// Last updated: 9/4/2026, 8:31:55 pm
1class Solution {
2public:
3    int findMinDifference(vector<string>& timePoints) {
4        if(timePoints.size() > 1440)
5            return 0;
6        
7        int n = timePoints.size();
8        vector<int>minutes(n+1);
9        
10        for(int i = 0;i < n; i++) {
11            int hr = stoi(timePoints[i].substr(0,2));
12            int mn = stoi(timePoints[i].substr(3,2));
13            minutes[i] = hr * 60 + mn;
14        }
15        sort(minutes.begin(),minutes.begin() + n);
16        minutes[n] = minutes[0] + 1440;
17        int minDiff = INT_MAX;
18        for(int i = 1;i <= n; i++) {
19            minDiff= min(minDiff, minutes[i] - minutes[i-1]);
20        }
21        return minDiff;
22    }
23};