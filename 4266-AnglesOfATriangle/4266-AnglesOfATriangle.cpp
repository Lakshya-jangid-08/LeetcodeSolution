// Last updated: 6/29/2026, 10:19:41 AM
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        
        int a = sides[0], b = sides[1], c = sides[2];

        if(a + b <= c) return {};
        else if(a + c <= b) return {};
        else if(c + b <= a) return {};
        cout << M_PI;
        double val = 180.0 / M_PI;
        double A = acos((b*b + c * c - a * a) / (2.0 * b * c)) * val;
        double B = acos((a*a + c * c - b * b) / (2.0 * a * c)) * val;
        double C = 180.0 - A - B;

        vector<double> res = {A, B, C};
        sort(res.begin(), res.end());
        return res;
    }
};