// Last updated: 4/4/2026, 6:07:19 pm
1class Node {
2 public:
3    int val;
4    Node* prev;
5    Node* next;
6
7    Node(int v) {
8        val = v;
9        prev = next = nullptr;
10    }
11};
12
13class MyCircularQueue {
14    Node* head;
15    Node* tail;
16    int curr;
17    int size;
18public:
19    MyCircularQueue(int k) {
20        head = tail = nullptr;
21        size = k;
22        curr = 0;
23    }
24    ~MyCircularQueue() {
25        while (curr > 0) {  
26            deQueue();
27        }
28    }
29    
30    bool enQueue(int value) {
31        if(curr == size) return false;
32        if(curr == 0) {
33            head = new Node(value);
34            head->next = head;
35            head->prev = head;
36            tail = head;
37            curr++;
38            return true;
39        }
40
41        Node* temp = new Node(value);
42        tail->next = temp;
43        temp->prev = tail;
44        temp->next = head;
45        head->prev = temp;
46        tail = temp;
47       
48        curr++;
49        return true;
50    }
51    
52    bool deQueue() {
53        if(curr == 0) return false;
54        if(curr == 1) {
55            delete head;
56            head = tail = nullptr;
57            curr--;
58            return true;
59        }
60        Node* toDelete = head;
61        head = head->next;
62        head->prev = tail;
63        tail->next = head;
64        delete toDelete;
65        curr--;
66        return true;
67    }
68    
69    int Front() {
70        if(curr == 0) return -1;
71        return head->val;
72    }
73    
74    int Rear() {
75        if(curr == 0) return -1;
76        return tail->val;
77    }
78    
79    bool isEmpty() {
80        return curr == 0;
81    }
82    
83    bool isFull() {
84        return curr == size;
85    }
86};
87
88/**
89 * Your MyCircularQueue object will be instantiated and called as such:
90 * MyCircularQueue* obj = new MyCircularQueue(k);
91 * bool param_1 = obj->enQueue(value);
92 * bool param_2 = obj->deQueue();
93 * int param_3 = obj->Front();
94 * int param_4 = obj->Rear();
95 * bool param_5 = obj->isEmpty();
96 * bool param_6 = obj->isFull();
97 */