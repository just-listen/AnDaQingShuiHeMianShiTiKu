#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    // bool verifyPostorder(vector<int>& postorder) {
    //     return recur(postorder, 0, postorder.size() - 1);
    // }
    // bool recur(vector<int>& postorder, int left, int right){
    //     if(left >= right) return true;
    //     int idx = left;
    //     while(postorder[idx] < postorder[right]) ++idx;
    //     int mid = idx;
    //     while(postorder[idx] > postorder[right]) ++idx;
    //     return idx == right && 
    //         recur(postorder, left, mid - 1) && recur(postorder, mid, right - 1);
    // }

    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stk;
        int root = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; --i){
            if(postorder[i] > root) return false;
            while(!stk.empty() && postorder[i] < stk.top()){
                root = stk.top();
                stk.pop();
            }
            stk.push(postorder[i]);
        }
        return true;
    }
};

int main(){
    vector<int> vec({4, 8, 6, 12, 16, 14, 10});
    Solution s;
    cout << s.verifyPostorder(vec) << endl;
    return 0;
}