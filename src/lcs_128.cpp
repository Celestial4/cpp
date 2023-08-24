#include "../include/disjointset.h"
#include "../include/header.h"

using namespace std;
int solve(std::vector<int> &nums)
{
    //初始化，cnt_map用于统计并查集中的集合代表节点数，每一个并查集表示一个连续的数字串
    //num_map用于索引实际的数字和它在数组中的下标，以便后续查找j
    map<int, int> num_map, cnt_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        cnt_map[i] = 0;
    }

    disjointset uf(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        auto cn = nums[i];
        if (num_map.find(cn) == num_map.end())
        {
            num_map[cn] = i;
            if (num_map.find(cn + 1) != num_map.end())
            {
                uf.union_(i, num_map[cn + 1]);
            }
            if (num_map.find(cn - 1) != num_map.end())
            {
                uf.union_(i, num_map[cn - 1]);
            }
        }
    }

    int m = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int c = uf.find(i);
        cnt_map[c]++;
        if(cnt_map[c]>m){
            m = cnt_map[c];
        }
    }
    return m;
}

void solve_128()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    std::cout<< solve(nums);
}