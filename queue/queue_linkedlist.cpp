# include <iostream>

using namepsace std;

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
    
    }
    
    int size(){
    
    }
    
    void push(const int val){
    
    }
    
    void pop(){
    
    }
    
    int get_front(){
    
    }
    
    int get_back(){
    
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
    cout << q.get_back() << endl;
    
    return 0;
}
