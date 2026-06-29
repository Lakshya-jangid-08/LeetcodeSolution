// Last updated: 6/29/2026, 10:19:50 AM
class Solution {
    int MOD = 1e9 + 7;
    
    int invFact[100001];
    int Fact[100001];

    int factorial(int n) {
        if( n < 2) return 1;
        if(Fact[n] != -1) return Fact[n];
        return Fact[n] = ( 1LL * n * factorial(n - 1) ) % MOD;
    }

    int inverseFactorial(int val, int pow) {
        int res = 1;
        int v = val;
        while(pow > 0) {
            if(pow & 1) res = (1LL * res * val) % MOD;
            val = (1LL * val * val) % MOD;
            pow = pow >> 1; 
        }
        return res;
    }

    int nCr(int n, int r) {
        
        if(n < r) return 0;
        if(n == r) return 1;

        if(n - r < r) {
            r = n - r;
        }

        int n_fact = factorial(n);
        int r_fact = factorial(r);
        int nr_fact = factorial(n - r);
        
        invFact[r] = (invFact[r] != -1 ? invFact[r] : inverseFactorial(r_fact, MOD - 2));
        invFact[n - r] = (invFact[n - r] != -1 ? invFact[ n - r] : inverseFactorial(nr_fact, MOD - 2));
        return (1LL * (1LL * (1LL * n_fact) % MOD * invFact[r] % MOD) * invFact[n - r]) % MOD;
    }    

public:
    int countVisiblePeople(int n, int pos, int k) {
        long int res = 0;
        
        memset(invFact, -1, sizeof(invFact));
        memset(Fact, -1, sizeof(Fact));
        
        // prevent TLE;
        Fact[n] = factorial(n);

        for(int x = 0; x <= k; x++) {

            int leftSide = nCr(pos, x);
            int rightSide = nCr(n - pos - 1, k - x);

            res = (1LL * res + (2LL * leftSide * rightSide) % MOD) % MOD;

        }
        
        return res;
    }
};