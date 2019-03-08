
/*

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {

}
};


*/


/*
分治法。

左下角的元素是这一行中最小的元素，同时又是这一列中最大的元素。比较左下角元素和目标：
若左下角元素等于目标，则找到
若左下角元素大于目标，则目标不可能存在于当前矩阵的最后一行，问题规模可以减小为在去掉最后一行的子矩阵中寻找目标
若左下角元素小于目标，则目标不可能存在于当前矩阵的第一列，问题规模可以减小为在去掉第一列的子矩阵中寻找目标
若最后矩阵减小为空，则说明不存在
*/
bool searchMatrix(vector<vector<int>>& matrix, int target)
{

	/*

	*/


	int row = matrix.size();
	if (row == 0) return false;
	int col = matrix[0].size();
	if (col == 0) return false;

	int i = row - 1;
	int j = 0;
	while (i>0 && j <col)
	{
		if (matrix[i][j] == target)
		{
			return true;
		}
		else if (matrix[i][j] < target)
		{
			j++;
		}
		else
		{
			i--;
		}
	}

	return false;
}

//c++ 先找打target在哪一行，然后具体在这一行应用二分查找
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	for (int i = 0; i<matrix.size(); i++)
	{
		//这里遍历找到哪一行需要花费O(n)的时间算法效率
		if (target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1])
			for (int low = 0, high = matrix[i].size() - 1; low <= high;)
			{
				int mid = (low + high) / 2;
				if (target>matrix[i][mid])
					low = mid + 1;
				else if (target < matrix[i][mid])
					high = mid - 1;
				else
					return true;
			}
	}
	return false;
}