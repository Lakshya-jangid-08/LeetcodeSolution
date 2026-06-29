// Last updated: 6/29/2026, 10:21:26 AM
class Solution {
public:
int maxEqualChocolates(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxElem = nums[n - 1];

    vector<long long> diff(n, 0);

    for(int i = 0; i < n; i++) {
        diff[i] = maxElem - nums[i];
    }

    vector<long long>prefix(n, 0);

    prefix[0] = diff[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + diff[i];
    }

 

    auto isPos = [&](int mid) -> bool {
        int l = -1;
        for(int r = mid - 1; r < n; r++) {
            
            long long chocolatesNeed = prefix[r] - (l < 0 ? 0 : prefix[l]);
            long long cost = abs(chocolatesNeed - 1LL * (r - l) * diff[r]); 

            if(cost <= k) return true;
            l++;
        }

        return false;        

    };

    int high = n;
    int low = 1;
    int ans = 1;

    while(high >= low) {
        int mid = (high + low) / 2;
        if(isPos(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
    int maxFrequency(vector<int>& nums, int k) {
        return maxEqualChocolates(nums, k);
    }
};