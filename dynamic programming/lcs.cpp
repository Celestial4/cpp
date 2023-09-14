#include <iostream>
#include <vector>
#include <string>

class LCS
{
public:
	LCS() {
	}
	~LCS() {}
	void init(std::vector<char> a, std::vector<char> b) {
		seq_a = a;
		seq_b = b;
		lcs = std::vector<std::vector<int>>(a.size(), std::vector<int>(b.size(), -1));
	}

	int solute() {
		return dp(seq_a.size() - 1, seq_b.size() - 1, path);
	}

	std::string print_path() {
		std::string s;
		for (auto i = path.rbegin(); i != path.rend(); i++)
			s.push_back(*i);
		return s;
	}

	int dp(int i, int j,std::vector<char>& path) {
		if (i == -1 || j == -1)
			return 0;
		if (seq_a[i]==seq_b[j])
		{
			path.push_back(seq_a[i]);
			return dp(i - 1, j - 1,path) + 1;
		}
		else
		{
			int c1 = dp(i - 1, j,path);
			int c2 = dp(i, j - 1,path);
			if (c1>=c2)
			{
				return c1;
			}
			else
			{
				return c2;
			}
		}
	}
	

private:
	std::vector<char> seq_a;
	std::vector<char> seq_b;

	std::vector<std::vector<int>> lcs;
	std::vector<char> path;
};
