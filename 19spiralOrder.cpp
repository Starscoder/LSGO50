/**
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix

**/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int u = 0;
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true){
            for(int i = l;i<=r;i++) res.push_back(matrix[u][i]);
            if(++u > d) break;
            for(int i = u;i<=d;i++) res.push_back(matrix[i][r]);
            if(--r<l) break;
            for(int i = r;i>=l;i--) res.push_back(matrix[d][i]);
            if(--d<u) break;
            for(int i = d;i>=u;i--) res.push_back(matrix[i][l]);
            if(++l>r) break;
        }
        return res;
    }
};
