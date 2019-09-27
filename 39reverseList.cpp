/**
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)    return NULL;
        ListNode *pre = NULL, *cur = head , *n = head->next;
        while(n != NULL){
            cur->next = pre;
            pre = cur;
            
            cur = n;
            n = n->next;
        }
        cur->next = pre;
        return cur;
    }
};
