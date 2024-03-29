/**
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fptr = head, *sptr = head, *tmp = head;
        bool flag = false;
        while(fptr != NULL && fptr->next != NULL){
            fptr  = fptr->next->next;
            sptr = sptr->next;
            if(fptr == sptr){
                flag = true;
                while(tmp != sptr){
                    tmp = tmp->next;    
                    sptr = sptr->next;
                }
                break;
            }
        }
        return flag?tmp:NULL;
    }
};
