// Last updated: 4/4/2026, 6:05:59 pm
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
24    
25    bool enQueue(int value) {
26        if(curr == size) return false;
27        if(curr == 0) {
28            head = new Node(value);
29            head->next = head;
30            head->prev = head;
31            tail = head;
32            curr++;
33            return true;
34        }
35
36        Node* temp = new Node(value);
37        tail->next = temp;
38        temp->prev = tail;
39        temp->next = head;
40        head->prev = temp;
41        tail = temp;
42       
43        curr++;
44        return true;
45    }
46    
47    bool deQueue() {
48        if(curr == 0) return false;
49        if(curr == 1) {
50            delete head;
51            head = tail = nullptr;
52            curr--;
53            return true;
54        }
55        Node* toDelete = head;
56        head = head->next;
57        head->prev = tail;
58        tail->next = head;
59        delete toDelete;
60        curr--;
61        return true;
62    }
63    
64    int Front() {
65        if(curr == 0) return -1;
66        return head->val;
67    }
68    
69    int Rear() {
70        if(curr == 0) return -1;
71        return tail->val;
72    }
73    
74    bool isEmpty() {
75        return curr == 0;
76    }
77    
78    bool isFull() {
79        return curr == size;
80    }
81};
82
83/**
84 * Your MyCircularQueue object will be instantiated and called as such:
85 * MyCircularQueue* obj = new MyCircularQueue(k);
86 * bool param_1 = obj->enQueue(value);
87 * bool param_2 = obj->deQueue();
88 * int param_3 = obj->Front();
89 * int param_4 = obj->Rear();
90 * bool param_5 = obj->isEmpty();
91 * bool param_6 = obj->isFull();
92 */