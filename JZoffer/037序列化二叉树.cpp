#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    string serialize(TreeNode* root) {
        if(root == nullptr) return "[]";
        string res = "[";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node){
                res.append(to_string(node->val) + ",");
                que.push(node->left);
                que.push(node->right);
            }
            else res.append("null,");
        }
        res.erase(res.size() - 1, 1);
        res.append("]");
        return res;
    }
    TreeNode* deserialize(string data) {
        if(data.compare("[]") == 0) return nullptr;
        vector<TreeNode*> vec;
        data.erase(0, 1);
        data.erase(data.size() - 1, 1);
        int len = data.size(), i = 0;
        while(i < len){
            string str = "";
            while(i < len && data[i] != ',') str += data[i++];
            if(str.compare("null") == 0){
                TreeNode *cur = nullptr;
                vec.push_back(cur);
            }
            else{
                TreeNode *cur = new TreeNode(stoi(str));
                vec.push_back(cur);
            }
            ++i;
        }
        int n = vec.size(), j = 1;
        for(int i= 0; j < n; ++i){
            if(vec[i] == nullptr) continue;
            if(j < n) vec[i]->left = vec[j++];
            if(j < n) vec[i]->right = vec[j++];
        }
        return vec[0];
    }
};

int main(){
    Solution s;
    cout << s.serialize(s.deserialize("[1,2,3,null,null,4,5]")) << endl;
    return 0;
}