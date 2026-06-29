// Last updated: 6/29/2026, 10:21:09 AM
class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        unordered_map<int, vector<long long>> prefixSum;
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            if(prefixSum.count(nums[i]) == 0) {
                prefixSum[nums[i]].push_back(i);
            } else {
                prefixSum[nums[i]].push_back( i + prefixSum[nums[i]].back() );
            }
        }

        vector<long long> res;

        for(int i = 0; i < n; i++) {
            auto &idxArr = mp[nums[i]]; 
            int pos = lower_bound(idxArr.begin(), idxArr.end(), i) - idxArr.begin();
            int m = idxArr.size();

            auto &psArr = prefixSum[ nums[i] ];

            long long val = 1LL * i * (pos + 1) - psArr[pos]  + (psArr.back() - psArr[pos]) - 1LL * i * (m - pos - 1);

            res.push_back(val);
        }
        return res;
    }
};