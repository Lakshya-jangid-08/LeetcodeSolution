// Last updated: 7/4/2026, 10:16:08 pm
1class KthLargest {
2    priority_queue<int , vector<int> , greater<int>> pq;
3    int k;
4
5public:
6    KthLargest(int k, vector<int>& a) {
7        this->k = k;
8
9        for(int x : a){
10            pq.push(x);
11            if(pq.size() > k) pq.pop();
12        }
13    }
14    
15    int add(int val) {
16        pq.push(val);
17
18        if(pq.size() > k) pq.pop();
19
20        return pq.top();
21    }
22};