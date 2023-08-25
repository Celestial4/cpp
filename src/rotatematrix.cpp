#include "../include/header.h"
#include "../include/util.h"

using namespace std;

void swap_array(vector<int>& l,vector<int> &r){
    vector<int> temp(r);
    r = l;
    l = temp;
}

void _solve_rotatematrix_48(vector<vector<int>>& m){
    int len = m.size();
    for (size_t i = 0; i < len/2; i++)
    {
        swap_array(m[i], m[len - i - 1]);
    }
    //交换对角线
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = i+1; j < len; j++)
        {
            util::swap(m[i][j], m[j][i]);
        }
    }
}