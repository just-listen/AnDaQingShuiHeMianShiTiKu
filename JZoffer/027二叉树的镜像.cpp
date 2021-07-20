#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *leftTree = mirrorTree(root->left);
        TreeNode *rightTree = mirrorTree(root->right);
        root->left = rightTree;
        root->right = leftTree;
        return root;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *node = stk.top();
            stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
};

int main(){
    
    return 0;
}