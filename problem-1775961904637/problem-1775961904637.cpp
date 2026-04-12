// Last updated: 12/4/2026, 8:15:04 am
1class Solution {
2public:
3    vector<double> internalAngles(vector<int>& sides) {
4        
5        int a = sides[0], b = sides[1], c = sides[2];
6
7        if(a + b <= c) return {};
8        else if(a + c <= b) return {};
9        else if(c + b <= a) return {};
10        cout << M_PI;
11        double val = 180.0 / M_PI;
12        double A = acos((b*b + c * c - a * a) / (2.0 * b * c)) * val;
13        double B = acos((a*a + c * c - b * b) / (2.0 * a * c)) * val;
14        double C = 180.0 - A - B;
15
16        vector<double> res = {A, B, C};
17        sort(res.begin(), res.end());
18        return res;
19    }
20};