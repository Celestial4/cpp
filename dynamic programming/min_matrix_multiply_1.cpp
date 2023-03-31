#include <iostream>
#include <vector>
#include <string>

#define MIN 9999999

//�þ����±�����ʾ���飬�߼���΢�鷳һ�㣬���׸����
class minmal_matrix_multiplication
{
public:
	minmal_matrix_multiplication() {};
	~minmal_matrix_multiplication() {};

	minmal_matrix_multiplication(std::initializer_list<int> list) :seqs(list.size()) {
		std::copy(list.begin(), list.end(), seqs.begin());
		int rc = list.size();
		comp = std::vector<std::vector<int>>(rc, std::vector<int>(rc,MIN));
	}

	void solute()
	{
		std::cout << dp(0, seqs.size()-1);

	}

private:

	std::vector<std::vector<int>> comp;

	int dp(int i, int j) {
		if (comp[i][j] < MIN)
		{
			return comp[i][j];
		}
		//��һ����
		if (j - i + 1 <= 2)
		{
			return 0;
		}
		//�����������
		if (j-i+1==3)
		{
			comp[i][j] = seqs[i]*seqs[i+1]*seqs[j];
			return comp[i][j];
		}
		int min = MIN;
		for (int k = i+1; k <= j-1; k++)
		{
			int left = dp(i, k);
			int right = dp(k, j);
			//Ψһ�ô�������������һ��
			int curnt = left+right+ seqs[i]*seqs[k]*seqs[j];
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
