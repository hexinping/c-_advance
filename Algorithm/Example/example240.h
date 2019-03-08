
/*

��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target���þ�������������ԣ�

ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
ʾ��:

���о��� matrix ���£�

[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
���� target = 5������ true��

���� target = 20������ false��

class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {

}
};


*/


/*
���η���

���½ǵ�Ԫ������һ������С��Ԫ�أ�ͬʱ������һ��������Ԫ�ء��Ƚ����½�Ԫ�غ�Ŀ�꣺
�����½�Ԫ�ص���Ŀ�꣬���ҵ�
�����½�Ԫ�ش���Ŀ�꣬��Ŀ�겻���ܴ����ڵ�ǰ��������һ�У������ģ���Լ�СΪ��ȥ�����һ�е��Ӿ�����Ѱ��Ŀ��
�����½�Ԫ��С��Ŀ�꣬��Ŀ�겻���ܴ����ڵ�ǰ����ĵ�һ�У������ģ���Լ�СΪ��ȥ����һ�е��Ӿ�����Ѱ��Ŀ��
���������СΪ�գ���˵��������
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

//c++ ���Ҵ�target����һ�У�Ȼ���������һ��Ӧ�ö��ֲ���
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	for (int i = 0; i<matrix.size(); i++)
	{
		//��������ҵ���һ����Ҫ����O(n)��ʱ���㷨Ч��
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