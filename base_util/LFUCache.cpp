#include "../include/LFUCache.h"

using namespace std;
using lfu = LFUCache;
using node = LFUCacheNode;
using list_ = LFUCache_deque;

LFUCache::LFUCache(/* args */)
{
    init(5);
}

LFUCache::LFUCache(int c)
{
    init(c);
}

void lfu::init(int c)
{
    capacity = c;
}

void lfu::put(int k, int v)
{
    if (kn_map.find(k) != kn_map.end())
    {
        node *p = kn_map[k];
        p->v = v;
        int old_f = p->f;
        list_ *lp = fl_map[old_f];
        // update freq-list map
        remove(p, lp);
        p->f++;
        if (fl_map.find(p->f) != fl_map.end())
        {
            list_ *nlp = fl_map[p->f];
            // if the number of element of deque under frequency f reach the capacity
            if (nlp->size == capacity)
            {
                remove(nlp->tail, nlp);
            }
            add(p, nlp);
        }
        else
        {
            add(p, fl_map[p->f]);
        }
    }
    else
    {
        node *p = new node();
        p->k = k;
        p->v = v;
        p->f = 1;
        p->next = p->pre = nullptr;
        kn_map[k] = p;

        if (fl_map.find(1) == fl_map.end())
        {
            list_ *nlp = new list_();
            nlp->size = 0;
            nlp->f = 1;
            nlp->tail = nlp->head = nullptr;
            fl_map[1] = nlp;
        }
        list_ *lp = fl_map[1];
        if (lp->size == capacity)
        {
            remove(lp->tail, lp);
        }
        add(p, lp);
    }
}

int lfu::get(int k)
{
    if (kn_map.find(k) != kn_map.end())
    {
        node *p = kn_map[k];

        remove(p, fl_map[p->f]);

        add(p, fl_map[p->f + 1]);
        return p->v;
    }
    return -1;
}

void lfu::add(node *p, list_ *&lp)
{
    if (lp == nullptr)
    {
        lp = new list_();
        lp->f = p->f;
        lp->head = lp->tail = p;
        lp->size = 1;
        return;
    }

    p->next = lp->head;
    if(lp->head == nullptr){
        lp->head = lp->tail = p;
        lp->size++;
        return;
    }
    lp->head->pre = p;
    lp->head = p;
    lp->size++;
}

void lfu::remove(node *p, list_ *lp)
{
    node *head = lp->head, *tail = lp->tail;
    if (p == head)
    {
        head = head->next;
        if (head == nullptr)
        {
            tail = head;
        }
        else
        {
            head->pre = nullptr;
        }
        p->next = nullptr;
        lp->head = head;
        lp->tail = tail;
        lp->size--;
        return;
    }
    if (p == tail)
    {
        tail = tail->pre;
        tail->next = nullptr;
        p->pre = nullptr;
        lp->tail = tail;
        lp->size--;
        return;
    }

    p->next->pre = p->pre;
    p->pre->next = p->next;
    p->next = p->pre = nullptr;
    lp->size--;
}
