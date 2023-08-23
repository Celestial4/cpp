#include <iostream>
#include <vector>
#include <string>

class rod {
	int len;
	int *price;
public:
	rod(std::initializer_list<int> list) :len{ static_cast<int>(list.size()) } {
		price = new int[len];
		std::copy(list.begin(), list.end(), price);
		tmp = std::vector<int>(len+1,-1);
		solution = std::vector<int>(len+1);
	}
private:
	std::vector<int> tmp, solution;
	int solution_len;
	int top_down_s(int n) {
		if (tmp[n] > 0)
			return tmp[n];
		if (n == 0)
			return 0;
		int max = -999999;
		for (size_t i = 1; i <= n/2+1; i++)
		{
			int cur = price[i-1] + top_down_s(n - i);
			if (cur > max) {
				max = cur;
				solution[n] = i;
			}
		}
		tmp[n] = max;
		return max;
	}
private:
	std::vector<int> d2t_res = std::vector<int>(len + 1, -1);

	int down_top_s(int n) {
		d2t_res[0] = 0;
		for (size_t j = 1; j <= n; j++)
		{
			int max = -99999;
			for (size_t i = 1; i <= j/2+1; i++)
			{
				int cur = price[i-1] + d2t_res[j - i];
				if (cur > max) {
					max = cur;
					solution[j] = i;
				}
			}
			d2t_res[j] = max;
		}
		return d2t_res[n];
	}
public:
	std::string print_solution() {
		int n = solution_len;
		std:: string res;
		while (n > 0)
		{
			res += std::to_string(solution[n])+',' ;
			n -= solution[n];
		}
		return res.substr(0, res.size() - 1);
	}

	int solute(int n) {
		solution_len = n;
		return top_down_s(solution_len);
	}

	int solute_2(int n) {
		solution_len = n;
		return down_top_s(solution_len);
	}
};