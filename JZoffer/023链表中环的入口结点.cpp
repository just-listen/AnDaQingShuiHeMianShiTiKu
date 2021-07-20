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
    ListNode* EntryNodeOfLoop(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode *slow = head, *fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        } while(fast != slow);
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    
    return 0;
}