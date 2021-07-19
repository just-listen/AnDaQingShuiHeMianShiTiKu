#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution{
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> vec{1,3,2};
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    for(int num : vec){
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    Solution s;
    vector<int> res = s.reversePrint(head->next);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}