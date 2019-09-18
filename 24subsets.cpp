/**
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
**/

class Solution {
public:
    void dfs(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,int level){
        if(level >= nums.size()){
            res.push_back(tmp);
            return ;
        }
        tmp.push_back(nums[level]);
        dfs(res,tmp,nums,level+1);
        tmp.pop_back();
        dfs(res,tmp,nums,level+1);
    }

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
    vector<int> tmp;
    dfs(res,tmp,nums,0);
    return res;
    }
};
