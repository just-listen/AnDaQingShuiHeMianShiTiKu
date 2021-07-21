#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution{
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node *cur = head, *nxt;
        //插入新节点
        while(cur){
            nxt = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = nxt;
            cur = nxt;
        }
        //复制random
        cur = head;
        while(cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        //拆分
        cur = head;
        Node *res = head->next;
        while(cur->next){
            nxt = cur->next;
            cur->next = cur->next->next;
            cur = nxt;
        }
        return res;
    }
};

int main(){
    
    return 0;
}