/**
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array

**/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1,mid = 0;
        while(low <=high){
            mid = partion(nums,low,high);
            if(mid == k-1)  return nums[mid];
            else if(mid > k-1)  high = mid-1;
            else    low = mid+1;
        }
        return -1;
    }
    int partion(vector<int>& nums,int low,int high){
        int left = low+1,right = high;
        swap(nums[low],nums[(left+right)/2]);
        int bound = nums[low];
        while(left <= right){
            while(nums[left] >= bound && left<high)   left++;
            while(nums[right] < bound)   right--;
            
            if(left<right)
                swap(nums[left++],nums[right--]);
            else    break;
        }
        swap(nums[low],nums[right]);
        return  right;
    }
};
