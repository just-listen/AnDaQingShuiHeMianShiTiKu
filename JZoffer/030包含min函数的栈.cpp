#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> inStk;
    stack<int> minStk;
public:
    MinStack() {}
    
    void push(int x) {
        if(minStk.empty() || x <= minStk.top()) minStk.push(x);
        inStk.push(x);
    }
    
    void pop() {
        if(minStk.top() == inStk.top()) minStk.pop();
        inStk.pop();
    }
    
    int top() {
        return inStk.top();
    }
    
    int min() {
        return minStk.top();
    }
};

int main(){
    
    return 0;
}