/*
数组209. 长度最小的子数组（中等）
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105


*/

using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0, r = 0, sum = 0, res = INT_MAX;
		while (r <= nums.size()) {
			if (sum < s) {
				if (r == nums.size()) break;
				sum += nums[r++];
			}
			else {
				res = min(res, r - l);
				sum -= nums[l++];
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};

int main() {
	int a[] = {2, 3, 1, 2, 4, 3};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	Solution solution;
	cout << solution.minSubArrayLen(7, nums) << endl;
}