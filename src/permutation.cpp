#include "../include/header.h"

using namespace std;

void test(std::vector<int> &v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i << " ";
    }
};

void perm(int index, const vector<int> &nums, vector<bool> &used, vector<int> &p, vector<vector<int>> &res)
{
    if (p.size() == nums.size())
    {
        vector<int> temp = p;
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            {
                continue;
            }
            p.push_back(nums[i]);
            used[i] = true;
            perm(index + 1, nums, used, p, res);
            used[i] = false;
            p.pop_back();
        }
    }
}

void solvePermutation1()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> res;
    vector<bool> used(n, false);
    vector<int> p;
    perm(0, nums, used, p, res);
    for (size_t i = 0; i < res.size(); i++)
    {
        for (auto &&j : res[i])
        {
            cout << j << ",";
        }
        cout << endl;
    }
}