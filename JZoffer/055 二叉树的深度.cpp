#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ++res;
        }
        return res;
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
    string str = "[3,9,20,null,null,15,7]";
    cout << s.maxDepth(deserialize(str)) << endl;
    return 0;
}