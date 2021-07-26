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
    //先序遍历 + 判断深度 （从顶至底）
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return abs(maxDepth(root->left) - maxDepth(root->right)) < 2 
        && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
class Solution2{
public:
    //后序遍历 + 剪枝 （从底至顶）
    bool isBalanced(TreeNode* root) {
        return maxDep(root) != -1;
    }
private:
    int maxDep(TreeNode* root){
        if(root == nullptr) return 0;
        int left = maxDep(root->left);
        if(left == -1) return -1;
        int right = maxDep(root->right);
        if(right == -1) return -1;
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};
int main(){
    Solution s;
    
    return 0;
}