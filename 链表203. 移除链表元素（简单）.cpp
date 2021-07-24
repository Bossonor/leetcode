/*
链表203. 移除链表元素（简单）
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 

示例 1：


输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]
 

提示：

列表中的节点数目在范围 [0, 104] 内
1 <= Node.val <= 50
0 <= val <= 50

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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *res = new ListNode();
		res->next = head;
		ListNode *cur = res;
		while (cur->next) {
			if (cur->next->val == val) {
				ListNode *tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else cur = cur->next;
		}
		head = res->next;
		delete res;
		return head;
	}
};

int main() {
	Solution solution;
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	for (int i = 2; i < 10; i++) {
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	head = solution.removeElements(head, 2);
	while(head){
			cout << head->val << endl;
			head = head->next;
	}
	delete head;
}