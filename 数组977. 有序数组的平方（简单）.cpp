/*
977. 有序数组的平方（简单）
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序

进阶：

请你设计时间复杂度为 O(n) 的算法解决本问题

*/

using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> res(nums.size());
		int l = 0, r = nums.size() - 1, k = nums.size() - 1;
		while (l <= r) {
			if (pow(nums[l], 2) >= pow(nums[r], 2)) {
				res[k] = pow(nums[l], 2);
				l++;
			}
			else {
				res[k] = pow(nums[r], 2);
				r--;
			}
			k--;
		}
		return res;
	}
};

int main() {
	int a[] = {-7, -3, 2, 3, 11};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	Solution solution;
	vector<int> res = solution.sortedSquares(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
}