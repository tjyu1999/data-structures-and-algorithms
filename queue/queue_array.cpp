# include <iostream>

using namespace std;

class Queue{
private:
    int *q;
    int front;
    int rear;
    int capacity;
    
    void double_capacity(){
        int j = front;
        int *tmp = new int [capacity * 2];
        
        for(int i = 1; i <= size(); i++) tmp[i] = q[++j % capacity];
        delete [] q;
        q = tmp;
        rear = size();
        front = 0;
        capacity *= 2;
    }
    
public:
    Queue(): capacity(10), front(0), rear(0){
        q = new int [capacity];
    }
    
    ~Queue(){
        delete [] q;
    }
    
    bool empty(){
        return front == rear;
    }
    
    int size(){
        return rear - front;
    }
    
    void push(const int val){
        if((rear + 1) % capacity == front) double_capacity();
        
        rear = (rear + 1) % capacity;
        q[rear] = val;
    }
    
    void pop(){
        if(empty()) throw "Queue is empty!";
        
        front = (front + 1) % capacity;
    }
    
    int get_front(){
        if(empty()) throw "Queue is empty!";
        return q[front + 1];
    }
    
    int get_back(){
        if(empty()) throw "Queue is empty!";
        return q[rear];
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
