// Last updated: 6/29/2026, 10:22:58 AM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = -1;
        int elem2 = -1;
        int f1 = 0, f2 = 0;

        for(int v : nums) {
            if (elem1 == v) {
                f1 += 1;
            } else if (elem2 == v) {
                f2 += 1;
            }  else if (f1 == 0) {
                elem1 = v;
                f1 = 1;
            } else if (f2 == 0) {
                elem2 = v;
                f2 = 1;
            } else {
                f1--;
                f2--;
            }
        }
    
        f1 = 0; f2 = 0;
        for(int v : nums) {
            if(elem1 == v) f1 += 1;
            else if(elem2 == v) f2 += 1;
        }
    
        vector<int> res;
        cout << elem1 << " " << elem2;
        if(f1 > nums.size() / 3) res.push_back(elem1);
        if(f2 > nums.size() / 3) res.push_back(elem2);
        return res;

    }
};