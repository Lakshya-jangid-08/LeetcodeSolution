// Last updated: 6/4/2026, 12:24:22 am
1class Solution {
2
3    string sumOfString(vector<string> & nums) {
4
5        string res = "";
6
7        int carry = 0;
8        int i = 1;
9
10        while(1) {
11            bool complete = true;
12            int val = 0;
13            for(auto &s : nums) {
14                int n = s.length();
15                if(n - i < 0) continue;
16                complete = false;
17                val += s[n - i] - '0';
18            }
19
20            val += carry;
21            carry = val / 10;
22            val %= 10; 
23            if(complete && !carry) {
24                if(val != 0)
25                    res = to_string(val) + res; 
26                return res;
27            }
28            res = to_string(val) + res; 
29            i++;
30        }
31
32        return res;
33    }
34public:
35    string multiply(string num1, string num2) {
36        if(num1 == "0" || num2 == "0") return "0";
37
38        int n = num1.length(), m = num2.length();
39        
40        vector<string> res(n, "");
41
42        for(int i = n - 1; i >= 0; i--) {
43            int carry = 0;
44            for(int j = m - 1; j >= 0; j--) {
45                int value = 0;
46                int mult = (num1[i] - '0') * (num2[j] - '0');
47                value = mult + carry;
48
49                carry = value / 10;
50                value %= 10;
51
52                res[i] = to_string(value) + res[i];
53            }
54            if(carry != 0) res[i] = to_string(carry) + res[i];
55        }
56        string zeroLead = "";
57
58        for(int i = n - 1; i >= 0; i--) {
59            res[i] = res[i] + zeroLead;
60            zeroLead += "0";
61        }
62
63        return sumOfString(res);
64    }
65};