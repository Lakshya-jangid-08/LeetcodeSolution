// Last updated: 6/5/2026, 5:05:32 PM
1class Solution {
2public:
3    int totalWaviness(int num1, int num2) {
4        
5        if(num2 <= 100) return 0; 
6
7        const auto check = [](int num) -> int {
8
9            int cnt = 0;
10
11            while(num >= 100) {
12                int prev = num % 10;
13                int curr = (num/10) % 10;
14                int next = (num/100) % 10;
15                if(prev > curr && curr < next) cnt++;
16                if(prev < curr && curr > next) cnt++;
17                num /= 10;
18            } 
19            return cnt;
20        };
21
22        int cnt = 0;
23
24        for(int num = max(100, num1); num <= num2; num++) {
25            cnt += check(num);
26        }
27
28        return cnt;
29    }
30};