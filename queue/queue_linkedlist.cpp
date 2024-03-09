# include <iostream>

using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(): data(0), next(0){};
    ListNode(int val): data(val), next(0){};
};

class Queue{
private:
    ListNode *front;
    ListNode *rear;
    int capacity;
    
public:
    Queue(): front(0), rear(0), capacity(0){};
    
    bool empty(){
        return (front && rear) == 0;
    }
    
    int size(){
        return capacity;
    }
    
    void push(const int val){
        if(empty()){
            front = new ListNode(val);
            rear = front;
            capacity++;
            return;
        }
        
        ListNode *tmp = new ListNode(val);
        rear->next = tmp;
        rear = tmp;
        capacity++;
    }
    
    void pop(){
        if(empty()) throw "Queue is empty";
        
        ListNode *del = front;
        front = front->next;
        delete del;
        del = 0;
        capacity--;
    }
    
    int get_front(){
        if(empty()) throw "Queue is empty";
        return front->data;
    }
    
    int get_back(){
        if(empty()) throw "Queue is empty";
        return rear->data;
    }
};

int main(){
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(4);
    q.push(5);
    
    while(!q.empty()){
        cout << q.get_front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}
