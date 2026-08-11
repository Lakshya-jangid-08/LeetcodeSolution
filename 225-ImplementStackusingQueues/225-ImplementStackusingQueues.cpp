// Last updated: 8/11/2026, 9:07:55 PM
1// Follow-up : Using 1 queue
2class MyStack {
3public:
4    queue<int> que;
5
6    MyStack() {
7        
8    }
9    
10    void push(int x) {
11        que.push(x);
12        int n = que.size(); 
13
14        for(int i=0; i<n-1; i++){
15            que.push(que.front());
16            que.pop();
17        }
18    }
19    
20    int pop() {
21        int result = que.front();
22        que.pop();
23
24        return result;
25    }
26    
27    int top() {
28        return que.front();
29    }
30    
31    bool empty() {
32        return que.empty();
33    }
34};