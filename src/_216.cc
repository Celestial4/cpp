#include "../include/header.h"

namespace l_216
{
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int sum)
        {
            int d = k - path.size();

            if (i < d)
            {
                return;
            }

            if (sum < 0 || sum > ((2 * i - d + 1) * d) / 2) //
            {
                return;
            }

            if (path.size() == k)
            {
                res.push_back(path);
                return;
            }

            for (int j = i; j > 0; j--)
            {
                path.push_back(j);
                dfs(j - 1, sum - j);
                path.pop_back();
            }
        };
        dfs(9, n);
        return res;
    }

    vector<vector<int>> combinationSum2(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int sum)
        {
            int d = k - path.size();

            if (sum < 0 || sum > ((2 * i - d + 1) * d) / 2) //
            {
                return;
            }

            if (path.size() == k)
            {
                res.push_back(path);
                return;
            }

            if (i > d)
            {
                dfs(i - 1, sum);
            }

            path.push_back(i);
            dfs(i - 1, sum - i);
            path.pop_back();
        };
        dfs(9, n);
        return res;
    }
} // namespace l_216
