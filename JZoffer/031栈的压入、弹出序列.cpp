#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int m = pushed.size(), popIdx = 0;
        for(int i = 0; i < m; ++i){
            stk.push(pushed[i]);
            while(!stk.empty() && stk.top() == popped[popIdx]){
                stk.pop();
                ++popIdx;
            }
        }
        return stk.empty();
    }
};

int main(){
    vector<int> pushed({1,2,3,4,5});
    // vector<int> popped({4,5,3,2,1});
    vector<int> popped({4,3,5,1,2});
    Solution s;
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}