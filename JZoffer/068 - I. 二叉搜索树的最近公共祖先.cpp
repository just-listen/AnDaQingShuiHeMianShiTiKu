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
        if(root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode *cur = root;
        while(cur){
            if(cur->val < p->val && cur->val < q->val) cur = cur->right;
            else if(cur->val > p->val && cur->val > q->val) cur = cur->left;
            else return cur;
        }
        return nullptr;
    }
};

TreeNode* deserialize(string& str){
    if(str.compare("[]")) return nullptr;
    str.erase(0, 1);
    str.erase(str.size() - 1, 0);
    vector<TreeNode*> vec;
    int i = 0, n = str.size();
    while(i < n){
        string tmp = "";
        while(i < n && str[i] != ',') tmp += str[i++];
        if(tmp.compare("null") == 0){
            TreeNode* cur = nullptr;
            vec.push_back(cur);
        }
        else{
            TreeNode* cur = new TreeNode(stoi(tmp));
            vec.push_back(cur);
        }
        ++i;
    }
    i = 0;
    for(int j = 1; j < vec.size(); ++i){
        if(vec[i] == nullptr) continue;
        if(j < vec.size()) vec[i]->left = vec[j++];
        if(j < vec.size()) vec[i]->right = vec[j++];
    }
    return vec[0];
}
int main(){
    Solution s;
    string str = " [6,2,8,0,4,7,9,null,null,3,5]";
    // cout << s.lowestCommonAncestor(deserialize(str),)
    return 0;
}