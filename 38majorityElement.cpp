/**
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
**/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums[0];
        int count = 0;
        for(int item:nums){
            if(count == 0)
                x = item;
            if(item == x)
                count++;
            else
                count--;
        }
        return x;
    }
};
