/*

�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]

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
			//Ϊ��һ��ѭ����׼��
			i++;
			j--;
		}

	} while (i<=j);

	if (left < j) //�ݹ����
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
	//��װ��һ��������,strcopy?? todo
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

	//ʹ�ÿ�������
	int left = 0;
	int right = _array.size() - 1;
	
	quickSort(_array, left, right);
	return _array;
}
