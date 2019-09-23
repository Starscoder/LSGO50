/**
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
**/



class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int s = nums[0];
        for(int i=1;i<nums.size();i++){
            s = s ^ nums[i]; 
        }
        return s;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_set<int> k;
        for(auto i:nums){
            if(k.count(i))
                k.erase(i);
            else
                k.insert(i);
        }
        for(auto j:k){
            ans = j;
        }
        return ans;
    }
};
