// Last updated: 6/4/2026, 12:46:53 PM
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
19        // d << endl;
20            return cnt;
21        };
22
23        int cnt = 0;
24
25        for(int num = max(100, num1); num <= num2; num++) {
26            cnt += check(num);
27            // d << cnt << endl;
28        }
29
30        return cnt;
31    }
32};