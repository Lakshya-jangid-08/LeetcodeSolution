// Last updated: 5/3/2026, 10:36:25 AM
1class Solution {
2public:
3
4    bool isPrime(int val) {
5        if(val == 1) return false;
6        for(int i = 2; i < val; i++) {
7            if(val % i == 0) return false;
8        }
9        return true;
10    } 
11    
12    int sumOfPrimesInRange(int n) {
13        string s = to_string(n);
14        reverse(s.begin(), s.end());
15        int r = stoi(s);
16        int l = min(n, r);
17        r = max(n, r);
18        int sum = 0;
19        for(int i = l; i <= r; i++) {
20            sum += (isPrime(i) ? i : 0);
21        }
22        return sum;
23    }
24};