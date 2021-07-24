/*
链表19. 删除链表的倒数第 N 个结点（中等）
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


*/

using namespace std;
#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dummy = new ListNode();
		dummy->next = head;
		ListNode *fast = dummy, *low = dummy;
		while (n--) fast = fast->next;
		while (fast->next) {
			fast = fast->next;
			low = low->next;
		}
		low->next = low->next->next;
		return dummy->next;
	}
};

int main() {
	Solution solution;
	ListNode *head = new ListNode(1);
	ListNode *tmp = head;
	for (int i = 2; i <= 4; i++) {
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	head = solution.removeNthFromEnd(head, 2);
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
}