#include "../include/header.h"
namespace l_131
{
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> P;
        function<bool(int, int)> is_r = [&](int i, int j) -> bool
        {
            while (s[i] == s[j])
            {
                i++;
                j--;
            }
            if (i >= j)
            {
                return true;
            }
            return false;
        };
        function<void(int)> f = [&](int index)
        {
            if (s.size() == index)
            {
                res.push_back(P);
                return;
            }
            for (int i = index; i < s.size(); i++)
            {
                if (is_r(index, i))
                {
                    P.push_back(s.substr(index, i + 1 - index));
                    f(i + 1);
                    P.pop_back();
                }
            }
        };

        f(0);
        return res;
    }

    vector<vector<string>> partition2(string s)
    {
        vector<vector<string>> res;
        vector<string> P;
        function<bool(int, int)> is_r = [&](int i, int j) -> bool
        {
            while (s[i] == s[j])
            {
                i++;
                j--;
            }
            if (i >= j)
            {
                return true;
            }
            return false;
        };
        function<void(int, int)> f = [&](int index, int start)
        {
            if (index == s.size())
            {
                res.push_back(P);
                return;
            }

            if (index < s.size() - 1)
                f(index + 1, start);

            if (is_r(start, index))
            {
                P.push_back(s.substr(start, index - start + 1));
                f(index + 1, index + 1);
                P.pop_back();
            }
        };

        f(0, 0);
        return res;
    }
} // namespace l_131

