namespace _22
{
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string path;

        function<void(int, int)> dfs = [&](int i, int j)
        {
            int l = path.size();

            if (l == 2 * n)
            {
                res.push_back(path);
                return;
            }

            if (j < n)
            {
                path.push_back('(');
                dfs(i + 1, j + 1);
                path.pop_back();
            }

            // i表示已经有几个符号了，j表示有几个左括号，i-j表示已有的右括号数,必须小于左括号数
            if (i - j < j)
            {
                path.push_back(')');
                dfs(i + 1, j);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return res;
    }
} // namespace _22
