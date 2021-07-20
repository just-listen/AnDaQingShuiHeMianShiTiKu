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
    //输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // A B 非空且以节点A为根节点的子树包含树 B 或A左子树包含B  或A右子树包含B
        return (A && B) && 
        (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
    bool recur(TreeNode *A, TreeNode *B){
        //当节点 *B* 为空：说明树 *B* 已匹配完成（越过叶子节点）
        //当节点 *A* 为空：说明已经越过树 *A* 叶子节点，匹配失败
        //当节点 *A* 和 *B* 的值不同：说明匹配失败
        if(B == nullptr) return true;
        if(A == nullptr || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};

int main(){
    
    return 0;
}