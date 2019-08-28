/**
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
**/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int start_pos = 0;
        int end_pos = 2 * n;
        int LMax1=0, RMin1=0, LMax2=0, RMin2=0;

        while(start_pos <= end_pos)
        {
            int c1 = (start_pos + end_pos) / 2;
            int c2 = m + n - c1;

            LMax1 = c1> 0 ? nums1[(c1-1)/2] : INT_MIN;
            RMin1 = c1 < 2 * n ? nums1[c1/2] : INT_MAX;
            LMax2 = c2 > 0 ? nums2[(c2-1)/2] : INT_MIN;
            RMin2 = c2 < 2 * m ? nums2[c2/2] : INT_MAX;

            if (LMax1 > RMin2)
            {
                end_pos = c1 - 1;
            }
            else if(LMax2 > RMin1)
            {
                start_pos = c1 + 1;
            }
            else
            {
                break;
            }
        }
        
        return (max<long>(LMax1, LMax2) + min<long>(RMin1, RMin2)) / 2.0;
    }
};
