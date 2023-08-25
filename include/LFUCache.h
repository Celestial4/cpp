#include "../include/header.h"
using namespace std;
struct LFUCacheNode
{
    int k, v ,f;
    LFUCacheNode *pre, *next;
};

struct LFUCache_deque
{
    LFUCacheNode *head, *tail;
    int f,size;
};

class LFUCache
{
private:
    //使用频率-双向链表map
    map<int, LFUCache_deque *> fl_map;
    //key-结点map
    map<int, LFUCacheNode *> kn_map;
    int capacity;
    void init(int capacity);
    void add(LFUCacheNode *p, LFUCache_deque*& list);
    void remove(LFUCacheNode *p, LFUCache_deque* list);

public:
    LFUCache(/* args */);
    LFUCache(int capacity);
    
    void put(int k, int v);
    int get(int k);
};
