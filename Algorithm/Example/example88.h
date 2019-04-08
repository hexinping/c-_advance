/*

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

*/

#include <iostream>
#include <vector>
using namespace std;


void swapNum(vector<int>& a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void quickSort(vector<int>& a, int left, int right)
{
	if (left > right) return;

	int middle = (left + right) / 2;
	int tmp = a[middle];
	int i = left, j = right;
	do 
	{
		while (a[i] < tmp&&i < right)
		{
			i++;
		}

		while (a[j]>tmp&&j > left) 
		{
			j--;
		}

		if (i <= j)
		{
			swapNum(a, i, j);
			//为下一次循环做准备
			i++;
			j--;
		}

	} while (i<=j);

	if (left < j) //递归左边
	{
		quickSort(a, left, j);
	}
	if (i < right)
	{
		quickSort(a, i, right);
	}

}


vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	//组装成一个大数组,strcopy?? todo
	std::vector<int> _array;
	for (int i = 0; i < m + n;i++)
	{
		if (i < m)
		{
			_array.push_back(nums1[i]);
		}
		else
		{
			_array.push_back(nums2[i-m]);
		}
	}

	//使用快排排序
	int left = 0;
	int right = _array.size() - 1;
	
	quickSort(_array, left, right);
	return _array;
}
