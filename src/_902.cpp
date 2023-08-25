#include "../include/header.h"
using namespace std;

bool greater_or_equal(vector<int> p, vector<int> q)
{
    int min_len = p.size() < q.size() ? p.size() : q.size();
    bool greater_is_p = p.size() > q.size();
    vector<int> res;
    for (size_t i = 0; i < min_len; i++)
    {
        res.push_back(p[i] - q[i]);
    }
    size_t i = 0;
    for (; i < res.size(); i++)
    {
        if(res[i] > 0)
            return true;
        if (res[i] < 0)
            break;
    }
    if (i < res.size() && res[i-1] == 0)
    {
        return false;
    }
    else
        return true;
}

void _solve_902(vector<int> &num, int index, vector<int> &nums, vector<int> &p, int &cnt)
{
    if (p.size() == num.size())
    {
        if (greater_or_equal(num, p))
            cnt++;
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (index > 0 || nums[i] <= num[0])
        {
            p.push_back(nums[i]);
            _solve_902(num, index + 1, nums, p, cnt);
            p.pop_back();
        }
    }
}

int atMostNGivenDigitSet(vector<string> &digits, int n)
{
    vector<int> num{};
    while (n > 0)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    vector<int> temp{}, nums;
    for (size_t i = 0; i < digits.size(); i++)
    {
        nums.push_back(digits[i][0] - '0');
    }
    rotate(num.begin(), num.end() - 1, num.end());
    int res = 0;
    _solve_902(num, 0, nums, temp, res);
    int options = digits.size();
    for (int i = 1; i < num.size(); i++)
    {
        res += pow(options, i);
    }
    return res;
}
