/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/suan-fa-xing-neng-fen-xi-dai-ma-shi-xian-by-yi-shi/

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//合并两个链表的函数
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p2=l1;
    l1=new ListNode(INT_MIN);//临时节点
    l1->next=p2;
    ListNode *p1=l1;
    while(l2&&p2){
        if(p1->val<=l2->val&&l2->val<=p2->val){
            p1->next=l2;
            p1=l2;
            l2=l2->next;
            p1->next=p2;      
        }
        else{
            p1=p2;
            p2=p2->next;
        }
    }
    if(!p2)
        p1->next=l2;
    return l1->next;  
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        deque< ListNode*>head_ptr_deque;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                head_ptr_deque.push_back(lists[i]);
            }
        }
        if(!head_ptr_deque.size())
            return NULL;
        ListNode *p1;
        ListNode *p2;       
        while(head_ptr_deque.size()!=1){
            p1=head_ptr_deque.back();
            head_ptr_deque.pop_back();
            p2=head_ptr_deque.back();
            head_ptr_deque.pop_back();
            //调用上面合并两个链表的函数
            head_ptr_deque.push_front(mergeTwoLists(p1, p2));
        }
        return head_ptr_deque.back();
    }
};



