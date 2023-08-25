#include "../include/header.h"

struct LRUCachNode
{
    LRUCachNode *pre, *next;
    int k, v;
};

class LRUCache
{
    LRUCachNode *head, *tail;
    int capacity;
    std::map<int, LRUCachNode *> cache;
    void init(int capacity);
    void remove(LRUCachNode *node);
    void add(LRUCachNode *node);

public:
    LRUCache();
    LRUCache(int capacity);
    void put(int k, int v);
    int get(int k);
};
