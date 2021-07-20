#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};
class Solution{
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *left = head, *right = head;
        while(k--){
            right = right->next;
            if(right == nullptr) return head;
        }
        while(right){
            right = right->next;
            left = left->next;
        }
        return left;
    }
};

int main(){
    
    return 0;
}