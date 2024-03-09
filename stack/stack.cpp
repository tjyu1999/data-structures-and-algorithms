# include <iostream>

using namespace std;

class Stack{
private:
    int *st;
    int top;
    int capacity;
    
    void double_capacity(){
        int *tmp = new int [capacity * 2];
        
        for(int i = 0; i < capacity; i++) tmp[i] = st[i];
        delete [] st;
        st = tmp;
        capacity *= 2;
    }

public:
    Stack(): top(-1), capacity(10){
        st = new int[capacity];
    }
    
    ~Stack(){
        delete [] st;
    }
    
    bool empty(){
        return top == -1;
    }
    
    int size(){
        return top + 1;
    }
    
    int get_top(){
        if(empty()) throw "Stack is empty!";
        return st[top];
    }
    
    void push(const int val){
        if(top == capacity - 1) double_capacity();
        st[++top] = val;
    }
    
    void pop(){
        if(empty()) throw "Stack is empty!";
        top--;
    }
};

int main(){
    Stack st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.push(4);
    st.push(5);

    while(!st.empty()){
        cout << st.get_top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}
