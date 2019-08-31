/**

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number

**/



class Solution {
public:
    bool isPalindrome(int x) {
        //思想是将x的前len/2位和后len/2位倒着乘除起来，如相等则为回文数
        if(x < 0)   return false;
        int len = 0;
        int copy = 0;
        for(int i = x; i; i /= 10)  ++ len;
        for(int j = len / 2; j > 0; -- j){      //倒着乘
            copy = copy * 10 + x % 10;
            x /= 10;
        }
        if(len % 2 == 1)    x /= 10;    //如果是奇数的话，直接比较中间左边和中间右边的数即可
        if(copy == x)   return true;
        return false;
    }
};
