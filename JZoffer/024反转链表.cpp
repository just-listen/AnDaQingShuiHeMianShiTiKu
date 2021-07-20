#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
};
class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy, *cur = head;
        while(cur){
            ListNode *nxt = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = nxt;
        }
        return dummy->next;
    }
};

int main(){
    
    return 0;
}