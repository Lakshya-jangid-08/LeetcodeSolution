// Last updated: 6/29/2026, 10:19:52 AM
class Solution {
    long long gcd(int a, int b) {
        long long x = a;
        long long y = b;

        while (y != 0) {
            long long temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
public:
    long long gcdSum(vector<int>& nums) {
        int maxelem = -1e8;
        int n = nums.size();
        vector<long long> pg(n,0);
        for(int i = 0; i < n; i++) {
            maxelem = max(maxelem, nums[i]);
            pg[i] = gcd(maxelem, nums[i]);
        }

        sort(pg.begin(), pg.end());
        long long sum = 0;
        for(int i = 0; i < n/2; i++) {
            sum += gcd(pg[i], pg[n-1 - i]);
        }
        return sum;
    }
};