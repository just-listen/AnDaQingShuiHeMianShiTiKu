#include<iostream>
#include<stack>
using namespace std;

// 两个栈，一个inStk负责入栈数据，一个outStk负责出栈数据,
// 当删除队头数据时，outStk先检查是否为空，空则从inStk(有数据)弹出并压栈，
class CQueue {
public:
    stack<int> inStk;
    stack<int> outStk;
    CQueue() {}
    
    void appendTail(int value) {
        inStk.push(value);
    }
    
    int deleteHead() {
        if(outStk.empty()){
            if(!inStk.empty()){
                while(!inStk.empty()){
                    outStk.push(inStk.top());
                    inStk.pop();
                }
            }
            else return -1;
        }
        int res = outStk.top();
        outStk.pop();
        return res;
    }
};

int main(){
    CQueue que;
    cout << que.deleteHead() << endl;
    que.appendTail(5);
    que.appendTail(2);
    cout << que.deleteHead() << endl;
    cout << que.deleteHead() << endl;
    return 0;
}