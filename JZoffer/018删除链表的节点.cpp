#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};
class Solution{
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        while(cur){
            if(cur->val == val){
                // ListNode *tmp = cur;
                prev->next = cur->next;
                // delete tmp;
            }
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main(){
    vector<int> vec{4,5,1,9};
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    for(int num : vec){
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    Solution s;

    return 0;
}