/**
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
**/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n-1)) == 0;
    }
};
