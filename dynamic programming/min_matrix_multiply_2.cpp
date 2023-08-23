#include <iostream>
#include <vector>
#include <string>

#define MIN 9999999

//ֱ���þ�����������Ȼ���ڼ������˷�ʱת���ɶ�Ӧ�ľ����±꣬�߼��򵥣������׳���
class minmal_matrix_multiplication
{
public:
	minmal_matrix_multiplication() {};
	~minmal_matrix_multiplication() {};

	minmal_matrix_multiplication(std::initializer_list<int> list) :seqs(list.size()) {
		std::copy(list.begin(), list.end(), seqs.begin());
		int rc = list.size();
		comp = std::vector<std::vector<int>>(rc, std::vector<int>(rc, MIN));
	}

	void solute()
	{
		std::cout << dp(1, seqs.size() - 1);
	}

private:

	std::vector<std::vector<int>> comp;

	int dp(int i, int j) {
		if (comp[i][j] < MIN)
		{
			return comp[i][j];
		}
		//�����������ʾ��һ������˷���0
		if (i == j)
			return 0;
		int min = MIN;
		for (int k = i; k <= j - 1; k++)
		{
			int left = dp(i, k);
			int right = dp(k + 1, j);
			//�����������������ľ������
			int curnt = left + right + seqs[i - 1] * seqs[k] * seqs[j];
			if (curnt < min)
			{
				min = curnt;
			}
		}
		comp[i][j] = min;
		return min;
	}



private:
	std::vector<int> seqs;

};