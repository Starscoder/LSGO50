/**
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
**/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)   return nums;
        int n = nums.size();
        vector<int> res(n,1);
        int left = 1,right = 1;
        for(int i=0;i<n;i++){
            res[i] *= left;
            left *= nums[i];
            
            res[n-i-1] *= right;
            right *= nums[n-i-1];
        }
        return res;
    }
};
