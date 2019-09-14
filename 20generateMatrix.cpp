/**
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii

**/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
    for(int s = 0, e = n - 1, m = 1; s<=e ; s++,e--){
        if(s==e) res[s][e] = m++;
        for (int j = s; j <= e-1; j++) res[s][j] = m++;
        for (int i = s; i <= e-1; i++) res[i][e] = m++;
        for (int j = e; j >= s+1; j--) res[e][j] = m++;
        for (int i = e; i >= s+1; i--) res[i][s] = m++;
    }
    return res;
    }
};
