/**
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


class Solution {
public:
	ListNode* sortList(ListNode* head) {
		quickSort(head, nullptr);
		return head;
	}

	void quickSort(ListNode* head, ListNode* tail) {
		if (head == tail || head->next == nullptr) {
			return;
		}

		ListNode* mid = partition(head, tail);

		quickSort(head, mid);
		quickSort(mid->next, tail);
	}

	ListNode* partition(ListNode* head, ListNode* tail) {

		int pivot = head->val;
		ListNode* s = head;
		ListNode* cur = head->next;
		while (cur != nullptr && cur != tail)
		{
			if (cur->val < pivot) {
				s = s->next;
				swap(s, cur);
			}
			cur = cur->next;
		}
		swap(s, head);
		return s;
	}


	void swap(ListNode* a, ListNode* b) {
		int temp = a->val;
		a->val = b->val;
		b->val = temp;
	}

};
