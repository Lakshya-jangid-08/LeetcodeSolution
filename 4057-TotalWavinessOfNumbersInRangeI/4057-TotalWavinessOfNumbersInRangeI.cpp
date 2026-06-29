// Last updated: 6/29/2026, 10:20:09 AM
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        
        if(num2 <= 100) return 0; 

        const auto check = [](int num) -> int {

            int cnt = 0;

            while(num >= 100) {
                int prev = num % 10;
                int curr = (num/10) % 10;
                int next = (num/100) % 10;
                if(prev > curr && curr < next) cnt++;
                if(prev < curr && curr > next) cnt++;
                num /= 10;
            } 
            return cnt;
        };

        int cnt = 0;

        for(int num = max(100, num1); num <= num2; num++) {
            cnt += check(num);
        }

        return cnt;
    }
};