#include "big.h"

std::vector<int> mul(const std::vector<int>& a, const std::vector<int>& b) {
	std::vector<int> res(a.size() + b.size() + 10);
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < b.size(); j++)
		{
			res[i+j] += a[i] * b[j];
		}
	}
	for (size_t i = 0; i < res.size()-1; i++)
	{
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	while (res.back() == 0)
	{
		res.pop_back();
	}
	std::reverse(res.begin(), res.end());
	return res;
}

std::vector<int> add(const std::vector<int>& a, const std::vector<int>& b) {
	std::vector<int> r(std::max(a.size(), b.size() + 5));

	for (int i = 0; i < a.size(); ++i)
		r[i] += a[i];

	for (int i = 0; i < b.size(); ++i)
		r[i] += b[i];

	for (size_t i = 0; i < r.size()-1; i++)
	{
		r[i + 1] += r[i] / 10;
		r[i] %= 10;
	}
	while (r.back()== 0)
		r.pop_back();
	std::reverse(r.begin(), r.end());
	return r;
}