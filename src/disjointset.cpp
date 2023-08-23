#include "../include/disjointset.h"

disjointset::disjointset(/* args */){};

disjointset::~disjointset(){};

disjointset::disjointset(int n)
{
    disjointset::n = n;
    parent = std::vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    rank = std::vector<int>(n);
}

disjointset make_disjointset(int n)
{
    return disjointset(n);
}

int disjointset::find(int n)
{
    int root = n;
    while (root != parent[root])
    {
        int p = parent[root];
        root = disjointset::find(p);
        parent[n] = root;
    }
    return root;
}

void disjointset::union_(int p, int q)
{
    int root_p = find(p);
    int root_q = find(q);
    if(root_p == root_q){
        return;
    }

    if (rank[root_p] > rank[root_q])
    {
        parent[root_q] = root_p;
    }
    else
    {
        parent[root_p] = root_q;
        if (rank[root_p] == rank[root_q])
        {
            rank[root_q]++;
        }
    }
}