#include "header.h"

class disjointset
{
private:
    int n;
    std::vector<int> parent, rank;

public:
    disjointset(/* args */);
    disjointset(int n);
    int find(int n);
    void union_(int p, int q);
    ~disjointset();
};

disjointset make_disjointset(int n);