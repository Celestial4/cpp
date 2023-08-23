#include "include/header.h"

#include "include/disjointset.h"
int main()
{
    // solvePermutation1();
    disjointset uf = make_disjointset(10);
    uf.union_(2, 3);
    uf.union_(2, 3);
    uf.find(2);
}