/**
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray

**/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int res = nums[0];
        
        for(int i = 1,j = nums.size();i<j;i++){
            sum = max(nums[i]+sum,nums[i]);
            res = max(sum,res);
        }
        return res;
    }
};
