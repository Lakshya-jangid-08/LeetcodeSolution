// Last updated: 8/11/2026, 9:27:24 PM
1class MyQueue {
2public:
3    stack<int> s1, s2;
4    
5    void push(int x) {
6        // 1. Move all elements from s1 to s2
7        while(!s1.empty()) {
8            s2.push(s1.top());
9            s1.pop();
10        }
11        
12        // 2. Push the new element to the bottom (empty s1)
13        s1.push(x);
14        
15        // 3. Move everything back to s1
16        while(!s2.empty()) {
17            s1.push(s2.top());
18            s2.pop();
19        }
20    }
21    
22    int pop() {
23        int top = s1.top(); 
24        s1.pop();
25        return top;
26    }
27    
28    int peek() {
29        return s1.top();
30    }
31    
32    bool empty() {
33        return s1.empty();
34    }
35};