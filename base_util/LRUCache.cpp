#include "../include/LRUCache.h"

using list_ = LRUCache;
using node = LRUCachNode;
list_::LRUCache()
{
    init(5);
}

list_::LRUCache(int c)
{
    init(c);
}

void list_::init(int capacity)
{
    list_::capacity = capacity;
    head = tail = nullptr;
}

void list_::put(int k, int v)
{
    if (cache.find(k) != cache.end())
    {
        node *n = cache[k];
        n->v = v;
        //更新缓存
        cache[k] = n;
        //更新链表
        remove(n);
        add(n);
    }
    else
    {
        node *p = new node();
        p->k = k;
        p->v = v;
        p->pre = p->next = nullptr;
        //缓存容量达到最大，清理最近最久未使用的结点
        if(cache.size() == capacity){
            cache.erase(tail->k);
            remove(tail);
        }
        cache[k] = p;
        add(p);
    }
}

int list_::get(int k)
{
    if (cache.find(k) != cache.end())
    {//找到结点，就更新它
        node *p = cache[k];
        remove(p);
        add(p);
        return p->v;
    }
    else
    {
        return -1;
    }
}

void list_::add(node *p)
{
    p->next = head;
    if (head != nullptr)
    {
        head->pre = p;
    }
    head = p;
    if (tail == nullptr)
    {
        tail = p;
    }
}

void list_::remove(node *p)
{
    if (p == head)
    {
        head = head->next;
        if (head != nullptr)
            head->pre = nullptr;
        else
            tail = head; //head为空，双向链表没有节点，因此将tail也值为空
        p->next = nullptr;
        return;
    }
    //隐含条件至少有两个结点
    if (p == tail)
    {
        tail = tail->pre;
        tail->next = nullptr;
        p->pre = nullptr;
        return;
    }

    p->next->pre = p->pre;
    p->pre->next = p->next;
    p->next = nullptr;
    p->pre = nullptr;
}