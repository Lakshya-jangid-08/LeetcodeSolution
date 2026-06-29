// Last updated: 6/29/2026, 10:22:51 AM
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> res;

        auto merged = [](vector<int>& v1, vector<int> &v2) -> vector<int> {
            int i = 0;
            int j = 0;
            vector<int> res;

            while(i < v1.size() && j < v2.size()) {
                if(v1[i] > v2[j]) {
                    res.push_back(v1[i++]);
                } else if(v1[i] < v2[j]) {
                    res.push_back(v2[j++]);
                } else {
                    int x = i;
                    int y = j;
                    while(x < v1.size() && y < v2.size() && v1[x] == v2[y]) {
                        x++; y++;
                    }
                    if(x == v1.size() && y == v2.size()) {
                        res.push_back(v2[j++]);
                    } else if (x == v1.size()) {
                        res.push_back(v2[j++]);
                    } else if (y == v2.size()) {
                        res.push_back(v1[i++]);
                    } else if(v1[x] > v2[y]) {
                        res.push_back(v1[i++]);
                    } else {
                        res.push_back(v2[j++]);
                    }
                }
            }
            while(i < v1.size()) {
                res.push_back(v1[i++]);
            }
            while(j < v2.size()) {
                res.push_back(v2[j++]);
            }
            return res;
        };

        auto maxSeq = [](vector<int> nums, int len) -> vector<int> {
            vector<int> res;
            int rm = nums.size() - len;

            for(auto &x : nums) {
                while(!res.empty() && res.back() < x && rm > 0) {
                    res.pop_back();
                    rm--;
                }
                res.push_back(x);
            }
            // trims extra node , because abhi rm > 0 ho skta hai
            res.resize(len);
            return res;
        };

        for(int i = max(0, k - m); i <= min(k, n); i++) {
            auto v1 = maxSeq(nums1, i);
            auto v2 = maxSeq(nums2, k - i);
            
            auto temp = merged(v1, v2);

            if(temp > res) res = temp;
        }

        return res;
    }
};