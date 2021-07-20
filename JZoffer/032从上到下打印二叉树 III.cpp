#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        deque<TreeNode*> deq;
        deq.push_back(root);
        while(!deq.empty()){
            int size = deq.size();
            vector<int> vec;
            for(int i = 0; i < size; ++i){
                if(res.size() % 2 == 0){
                    TreeNode *node = deq.front();
                    deq.pop_front();
                    vec.push_back(node->val);
                    if(node->left) deq.push_back(node->left);
                    if(node->right) deq.push_back(node->right);
                }
                else {
                    TreeNode *node = deq.back();
                    deq.pop_back();
                    vec.push_back(node->val);
                    if(node->right) deq.push_front(node->right);
                    if(node->left) deq.push_front(node->left);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main(){
    
    return 0;
}