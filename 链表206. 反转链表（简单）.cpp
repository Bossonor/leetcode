/*
链表206. 反转链表（简单）
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

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
	ListNode* reverseList(ListNode* head) {
		ListNode *res = nullptr;
		ListNode *pre = head;
		while (pre) {
			ListNode *tmp = pre->next;
			pre->next = res;
			res = pre;
			pre = tmp;
		}
		return res;
	}
};
//递归
/*class Solution {
public:
	ListNode* reverse(ListNode* pre, ListNode* cur) {
		if (cur == NULL) return pre;
		ListNode* temp = cur->next;
		cur->next = pre;
		// 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
		// pre = cur;
		// cur = temp;
		return reverse(cur, temp);
	}
	ListNode* reverseList(ListNode* head) {
		// 和双指针法初始化是一样的逻辑
		// ListNode* cur = head;
		// ListNode* pre = NULL;
		return reverse(NULL, head);
	}

};*/

int main() {
	Solution solution;
	ListNode *head = new ListNode(1);
	ListNode *tmp = head;
	for (int i = 2; i <= 5; i++) {
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	head = solution.reverseList(head);
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
}