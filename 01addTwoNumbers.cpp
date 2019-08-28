/**给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
		ListNode *newList = l1, *pre ;  //newList指向返回的链表，pre记录保存链表的当前指针的的前一个位置。
		int flag = 0;  //进位标志
		while (l1||l2)
		{
			int value;  //两个链表的每一位相加的和
			(l1) ? (pre = l1,l1 = l1->next, value = pre->val + flag) : (pre->next=l2, pre = l2, value= flag);
			(l2) ? (value += l2->val, l2 = l2->next) : (pre->next=l1);
			pre->val = value % 10;
			(value > 9) ? (flag = 1) : (flag = 0);
		}
		if (l1 == NULL && l2 == NULL && flag == 1)
			pre->next = new ListNode(1);
		return newList;
        
    }
};
