/**
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        if(root->val > max(p->val,q->val))return lowestCommonAncestor(root->left,p,q);
        else if(root->val < min(p->val,q->val))return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         TreeNode* anc = root;
        while(anc != NULL){
            if(anc->val < p->val && anc->val < q->val)
                anc = anc->right;
            else if(anc->val > p->val && anc->val > q->val)
                anc = anc->left;
            else return anc;
        }
        return NULL;
    }
};
