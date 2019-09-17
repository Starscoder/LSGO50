/**
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
**/


class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        vector<int> s(n+1,-1);
        s[1] = 1;
        s[2] = 2;
        for(int i = 3;i<=n;i++){
             s[i] = s[i-1] + s[i-2];
        }
        return s[n];
         // double sqrt5=sqrt(5);
        // double fibn=pow((1+sqrt5)/2,n+1)-pow((1-sqrt5)/2,n+1);
        // return (int)(fibn/sqrt5);
    }
};
