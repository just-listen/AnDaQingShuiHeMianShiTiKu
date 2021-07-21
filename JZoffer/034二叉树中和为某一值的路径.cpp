#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void dfs(TreeNode* root, int sum){
        if(root == nullptr) return;
        path.push_back(root->val);
        if(!root->left && !root->right && sum - root->val == 0) {
            res.push_back(path);
            // return;
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        path.pop_back();
    }
};

int main(){
    
    return 0;
}