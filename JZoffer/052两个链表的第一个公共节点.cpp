#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};
class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode *L1 = headA, *L2 = headB;
        while(L1 != L2){
            L1 = L1 == nullptr ? headB : L1->next;
            L2 = L2 == nullptr ? headA : L2->next;
        }
        return L1;
    }
};

int main(){
    
    return 0;
}