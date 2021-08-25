#include<unordered_map>
using namespace std;
// 双向链表 + 哈希表
struct DoubleLinkList{
    int key, val;
    DoubleLinkList *prev, *next;
    DoubleLinkList() : key(0), val(0), next(nullptr), prev(nullptr) {}
    DoubleLinkList(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
};

class LRUCache{
public:
    LRUCache(int _capacity) : capacity(_capacity), size(0){// 使用伪头部和伪尾部节点
        head = new DoubleLinkList();
        tail = new DoubleLinkList();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key){
        if(cache.count(key) == 0) return -1;
        DoubleLinkList *node = cache[key];
        moveToHead(node);
        return node->val;
    }
    void put(int key, int val){
        if(!cache.count(key)){
            DoubleLinkList *node = new DoubleLinkList(key, val);
            addToHead(node);
            cache[key] = node;
            ++size;
            if(size > capacity){
                DoubleLinkList *tmp = removeTail();
                cache.erase(tmp->key);
                delete tmp;
                --size;
            }
        }
        else{
            cache[key]->val = val;
            moveToHead(cache[key]);
        }
    }
private:
    void moveToHead(DoubleLinkList* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addToHead(node);
    }
    void addToHead(DoubleLinkList* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    DoubleLinkList* removeTail(){
        DoubleLinkList* tmp = tail->prev;
        tail->prev = tmp->prev;
        tmp->prev->next = tail;
        return tmp;
    }
    int size, capacity;
    DoubleLinkList *head, *tail;
    unordered_map<int, DoubleLinkList*> cache;
};