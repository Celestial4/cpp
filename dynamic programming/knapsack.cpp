#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct node
{
	int weight;
	int value;
};

class Knapsack
{
public:
	Knapsack() {};

	Knapsack(std::initializer_list<node> ls)
	{
		auto i = ls.begin();
		for (; i != ls.end()-1; i++)
		{
			values.push_back(*i);
		}
		max_weight = (*i).weight;
		solution = std::vector<std::vector<std::vector<int>>>(ls.size(), std::vector<std::vector<int>>(ls.size(), std::vector<int>(max_weight + 1, -1)));
	}

	void resolve() {
		std::cout << "total values:" << dp(0, values.size() - 1,max_weight) << std::endl;
		std::cout << "solution:" << std::endl;
		print_solution();
	}

	void print_solution(){
		int weight = max_weight;
		while (weight > 0)
		{
			int x = choice[weight];
			weight -= x;
			std::cout << x << (choice[weight] > 0 ? "," : "");

			if (!choice[weight])
				break;
		}
	}

	int dp(int i, int j, int m) {
		if (solution[i][j][m] != -1)
			return solution[i][j][m];

		if (i == j)
		{
			if (values[i].weight <= m)
			{
				choice.insert({ m,values[i].weight });
				return values[i].value;
			}
			else
				return 0;
		}
		int inc_val = 0;
		if (values[i].weight <= m)
			inc_val = values[i].value + dp(i + 1, j, m - values[i].weight);

		int exc_val = dp(i + 1, j, m);
		if (inc_val == 0 && exc_val == 0)
			return 0;

		if (inc_val >= exc_val) {
			if (choice.find(m) != choice.end()) {
				choice[m] = values[i].weight;
			}else
				choice[m] = values[i].weight;
			solution[i][j][m] = inc_val;
			return inc_val;
		}
		else {
			solution[i][j][m] = exc_val;
			return exc_val;
		}
	}
	~Knapsack() {};

private:
	std::vector<node> values;
	std::vector<std::vector<std::vector<int>>> solution;
	std::map<int, int> choice;
	int max_weight;
};