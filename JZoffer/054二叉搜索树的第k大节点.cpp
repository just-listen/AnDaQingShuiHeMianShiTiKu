#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    int kthLargest(TreeNode* root, int k) {
        this->K = k;
        dfs(root);
        return res;
    }
private:
    int K, res;
    void dfs(TreeNode* root){
        if(root ==nullptr) return ;
        dfs(root->right);
        if(K == 0) return;
        if(--K == 0) res = root->val;
        dfs(root->left);
    }
};

TreeNode* deserialize(string& str){
    if(str.compare("[]") == 0) return nullptr;
    str.erase(0, 1);
    str.erase(str.size() - 1, 1);
    int i = 0, len = str.size();
    vector<TreeNode*> vec;
    while(i < len){
        string tmp = "";
        while(i < len && str[i] != ',') tmp += (str[i++]);
        if(tmp.compare("null") == 0) {
            TreeNode* node = nullptr;
            vec.push_back(node);
        }
        else{
            TreeNode* node = new TreeNode(stoi(tmp));
            vec.push_back(node);
        }
        ++i;
    }
    int left = 0, right = 1;
    for(; right < vec.size(); ++left){
        if(vec[left] == nullptr)  continue;
        if(right < vec.size()) vec[left]->left = vec[right++];
        if(right < vec.size()) vec[left]->right = vec[right++];
    }
    return vec[0];
}

int main(){
    Solution s;
    string str = "[5,3,6,2,4,null,null,1]";
    cout << s.kthLargest(deserialize(str), 3) << endl;
    return 0;
}