# include <iostream>

using namespace std;

const int default_size = 10;

class Queue{
public:
    Queue(){
        q = new int[default_size];
        front = -1;
        rear = -1;
    }
    
    ~Queue(){
        delete[] q;
    }
    
    void push(int val){
        q[++rear] = val;
    }
    
    void pop(){
        if(empty()) throw "Queue is empty!";
        front++;
    }
    
    int get_front(){
        if(empty()) throw "Queue is empty!";
        return q[front + 1];
    }
    
    int get_back(){
        if(empty()) throw "Queue is empty!";
        return q[rear];
    }
    
    int size(){
        return rear - front;
    }
    
    bool full(){
        return rear == default_size - 1;
    }
    
    bool empty(){
        return front == rear;
    }

private:
    int* q;
    int front;
    int rear;
};

int main(){
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);
    
    while(!q.empty()){
        cout << q.get_front() << " ";
        q.pop();
    }
    cout << endl;
    
    // q.pop();
    /*
    cout << q.get_front() << endl;
    cout << q.get_back() << endl;
    cout << q.size() << endl;
    */
    return 0;
}
