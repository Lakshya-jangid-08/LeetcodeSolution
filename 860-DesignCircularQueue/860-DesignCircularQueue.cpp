// Last updated: 6/29/2026, 10:22:09 AM
class Node {
 public:
    int val;
    Node* prev;
    Node* next;

    Node(int v) {
        val = v;
        prev = next = nullptr;
    }
};

class MyCircularQueue {
    Node* head;
    Node* tail;
    int curr;
    int size;
public:
    MyCircularQueue(int k) {
        head = tail = nullptr;
        size = k;
        curr = 0;
    }
    ~MyCircularQueue() {
        while (curr > 0) {  
            deQueue();
        }
    }
    
    bool enQueue(int value) {
        if(curr == size) return false;
        if(curr == 0) {
            head = new Node(value);
            head->next = head;
            head->prev = head;
            tail = head;
            curr++;
            return true;
        }

        Node* temp = new Node(value);
        tail->next = temp;
        temp->prev = tail;
        temp->next = head;
        head->prev = temp;
        tail = temp;
       
        curr++;
        return true;
    }
    
    bool deQueue() {
        if(curr == 0) return false;
        if(curr == 1) {
            delete head;
            head = tail = nullptr;
            curr--;
            return true;
        }
        Node* toDelete = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete toDelete;
        curr--;
        return true;
    }
    
    int Front() {
        if(curr == 0) return -1;
        return head->val;
    }
    
    int Rear() {
        if(curr == 0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return curr == 0;
    }
    
    bool isFull() {
        return curr == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */