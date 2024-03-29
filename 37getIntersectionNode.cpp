/**
编写一个程序，找到两个单链表相交的起始节点。
示例 1：

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB ==nullptr) return nullptr;
        int la = 0,lb = 0;
        ListNode *tmp = headA;
        while(tmp){
            la++;
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            lb++;
            tmp = tmp->next;
        }
        int i = max(la,lb) - min(la,lb);
        if(la>lb){
            for(i;i>0;i--)
                headA = headA->next;
        }
        else{
            for(i;i>0;i--)
                headB = headB->next;
        }
        while(headA){
            if(headA == headB)  return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
