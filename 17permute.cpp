/**
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations

**/

class Solution {
public:
    void back_track(vector<int>& nums,vector<vector<int>> &res ,int i){
        if(i == nums.size()){
            res.push_back(nums);
        }
        for(int j = i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            back_track(nums,res,i+1);
            swap(nums[i],nums[j]);
        }
    }
    
    void swap(int &a,int &b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        back_track(nums,res,0);
        return res;
    }
};
