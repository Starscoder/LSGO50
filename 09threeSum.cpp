/**
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum

**/




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        sort(nums.begin(),nums.end());
        if(nums.empty() || nums.front()>0 || nums.back()<0)
            return {};
        
        for(int i=0;i<nums.size();i++){
            int fix=nums[i];
            if(fix>0)   break;
            if(i>0 && fix==nums[i-1])    continue;
            //对撞指针
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==-fix  ){
                    if(l==i+1 || r==nums.size()-1){
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    else if(nums[l]==nums[l-1])
                        l++;
                    else if(nums[r]==nums[r+1])
                        r--;
                    else{
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    
                }
                else if(nums[l]+nums[r]<-fix)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};
