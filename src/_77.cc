#include "../include/header.h"


vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> path;
    function<void(int, int)> f = [&](int i, int j)
    {
        if (i <= n - j)
        {
            return;
        }
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        f(i - 1, j);

        path.push_back(i);
        f(i - 1, j - 1);
        path.pop_back();
    };
    f(n, k);
    return res;
}