/**
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
**/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归中序遍历算法：
 
class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int cur = 0;
        inorder(root,cur,k,res);
        return res;
    }
    void inorder(TreeNode* root,int& cur,int k,int& res){
        if(!root)   return ;
        inorder(root->left,cur,k,res);
        cur++;
        if(cur == k){
            res = root->val;
            return ;
        }
        inorder(root->right,cur,k,res);
    }
};

//非递归算法：
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int cnt = 0;
        TreeNode* p = root;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;
            }
            else{
                cnt++;
                TreeNode* tmp = s.top();
                if(cnt == k){
                    return tmp->val;
                }
                s.pop();
                p = tmp->right;
            }
        }
        return -1;
    }
};
