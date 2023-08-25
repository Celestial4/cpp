#include "include/header.h"

#include "include/util.h"
#include "include/LRUCach.h"
using namespace std;
int main()
{
    LRUCache cache;
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(3, 3);
    cache.put(4, 4);
    cache.get(2);
    cache.put(5, 5);
    cache.put(6, 1);
    cout << cache.get(1);
}