#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};

int main(){
    Solution s;
    
    return 0;
}