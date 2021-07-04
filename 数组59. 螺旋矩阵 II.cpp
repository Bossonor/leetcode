/*
数组59. 螺旋矩阵 II（中等）
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20

*/

using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n));
		int low = 0, high = n - 1, num = 1;
		while (high >= low) {
			if (high == low) {
				res[low][low] = num;
				break;
			}
			else {
				int i = low, j = low;
				while (i < high) res[low][i++] = num++;
				while (j < high) res[j++][high] = num++;
				while (i > low) res[high][i--] = num++;
				while (j > low) res[j--][low] = num++;
				high--;
				low++;
			}
		}
		return res;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> nums = solution.generateMatrix(3);
	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 3; j++) {
			cout << nums[i][j] << ' ';
		}
	}
}