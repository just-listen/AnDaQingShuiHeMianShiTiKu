#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if(minHeap.size() == maxHeap.size()){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else{   //minHeap.size() >= maxHeap.size()
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) 
            return double(minHeap.top() + maxHeap.top()) / 2;
        else return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
};

int main(){
    // Solution s;
    
    return 0;
}