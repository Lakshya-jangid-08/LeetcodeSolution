// Last updated: 4/15/2026, 10:24:19 AM
1class Solution {
2public:
3int maxEqualChocolates(vector<int>& nums, int k) {
4    sort(nums.begin(), nums.end());
5    int n = nums.size();
6    int maxElem = nums[n - 1];
7
8    vector<long long> diff(n, 0);
9
10    for(int i = 0; i < n; i++) {
11        diff[i] = maxElem - nums[i];
12    }
13
14    vector<long long>prefix(n, 0);
15
16    prefix[0] = diff[0];
17    for(int i = 1; i < n; i++) {
18        prefix[i] = prefix[i - 1] + diff[i];
19    }
20
21 
22
23    auto isPos = [&](int mid) -> bool {
24        int l = -1;
25        for(int r = mid - 1; r < n; r++) {
26            
27            long long chocolatesNeed = prefix[r] - (l < 0 ? 0 : prefix[l]);
28            long long cost = abs(chocolatesNeed - 1LL * (r - l) * diff[r]); 
29
30            if(cost <= k) return true;
31            l++;
32        }
33
34        return false;        
35
36    };
37
38    int high = n;
39    int low = 1;
40    int ans = 1;
41
42    while(high >= low) {
43        int mid = (high + low) / 2;
44        if(isPos(mid)) {
45            ans = mid;
46            low = mid + 1;
47        } else {
48            high = mid - 1;
49        }
50    }
51    return ans;
52}
53    int maxFrequency(vector<int>& nums, int k) {
54        return maxEqualChocolates(nums, k);
55    }
56};