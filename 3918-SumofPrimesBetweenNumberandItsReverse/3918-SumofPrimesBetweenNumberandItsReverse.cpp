// Last updated: 5/3/2026, 10:36:49 AM
class Solution {
public:
    int reverseInt(int n){
        int rev = 0;
        while (n > 0){
            rev = rev * 10 + n % 10;
            n/=10;
        }
        return rev;
    }
    bool isPrime(int num){
        if (num < 2) return false;
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }
    
    int sumOfPrimesInRange(int n) {
        int r = reverseInt(n);
        int start = min(n,r);
        int end = max(n,r);
        int totalSum=0;
        for(int i = start; i <=end; i++){
            if (isPrime(i)) {
                totalSum +=i;
            }
        }
        return totalSum;
    }
};