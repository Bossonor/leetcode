﻿/*
链表24. 两两交换链表中的节点（中等）
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）

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
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = dummy->next;
		while (cur && cur->next) {
			ListNode *lat = cur->next;
			ListNode *tmp = lat->next;
			pre->next = lat;
			lat->next = cur;
			cur->next = tmp;
			pre = cur;
			cur = tmp;
		}
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
	head = solution.swapPairs(head);
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
}