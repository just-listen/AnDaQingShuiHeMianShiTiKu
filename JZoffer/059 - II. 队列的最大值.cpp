#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

class MaxQueue {
public:
    MaxQueue() { }
    int max_value() {
        return deq.empty() ? -1 : deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while(!deq.empty() && value > deq.back()) deq.pop_back();
        deq.push_back(value);
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int res = que.front();
        if(deq.front() == res) deq.pop_front();
        que.pop();
        return res;
    }
private:
    queue<int> que;
    deque<int> deq;
};

int main(){
    // Solution s;
    
    return 0;
}