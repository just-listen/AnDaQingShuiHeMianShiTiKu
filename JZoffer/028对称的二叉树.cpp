#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    bool isSymmetric(TreeNode* root) {
        return root ? recur(root->left, root->right) : true;
    }
    bool recur(TreeNode *L, TreeNode *R){
        if(!L && !R) return true;
        if(!L || !R) return false;
        if(L->val != R->val) return false;
        return recur(L->left, R->right) && recur(L->right, R->left);
    }
};

int main(){
    
    return 0;
}