#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        int in_idx = 0;
        //遍历前序遍历的每个元素
        for(int i = 1; i < preorder.size(); i++){
            TreeNode* temp = stk.top();
            //不等于，将当前元素作为其上一个元素的左子节点，并将当前元素压入栈内
            if(temp->val != inorder[in_idx]){
                temp->left = new TreeNode(preorder[i]);
                stk.push(temp->left);
            }
            else{
                //等于,从栈内弹出一个元素，同时令中序遍历下标指向下一个元素
                while(!stk.empty() && stk.top()->val == inorder[in_idx]){
                    temp = stk.top();
                    stk.pop();
                    in_idx++;
                }
                //令当前元素为最后一个相等元素的右节点
                temp->right = new TreeNode(preorder[i]);
                stk.push(temp->right);
            }
        }
        return root;
    }
};

class Solution2{
public:
    unordered_map<int, int> umap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 将中序序列用哈希表存储，便于查找根节点
        for(int i = 0; i < inorder.size(); ++i){
            umap[inorder[i]] = i;
        }
        // 传入参数：前序,中序，前序序列根节点，中序序列左边界，中序序列右边界
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_root, int in_left, int in_right){
        if(in_left > in_right) return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_root]);
        // 根节点在中序序列中的位置，用于划分左右子树的边界
        int in_root = umap[preorder[pre_root]];
        // 左子树在前序中的根节点位于：pre_root+1,左子树在中序中的边界：[in_left,in_root-1]
        root->left = buildTree(preorder, inorder, pre_root + 1, in_left, in_root - 1);
        // 右子树在前序中的根节点位于：根节点+左子树长度+1 = pre_root+in_root-in_left+1
        // 右子树在中序中的边界：[in_root+1,in_right]
        root->right = buildTree(preorder, inorder, pre_root + 1 + in_root - in_left, in_root + 1, in_right);
        return root;
    }
};

int main(){
    
    return 0;
}