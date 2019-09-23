/**

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum

本题的思路是：
    使用递归，递归出口是节点为空时返回0，否则返回其左右孩子节点（如果有）的节点值之一加上根节点的节点值的最大值，还有一种情况是根节点加上左右孩子节点的
 值最大，则将maxSum参数使用引用传递，取它们的和的最大值，依次递归。
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
class Solution {
public:
    int maxPath(TreeNode* root,int& maxSum){
        if(root == NULL)    return 0;
        int left = max(maxPath(root->left,maxSum),0);
        int right = max(maxPath(root->right,maxSum),0);
        maxSum = max(left + right + root->val,maxSum);
        return max(left + root->val,right + root-> val);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPath(root,maxSum);
        return maxSum;
    }
};
