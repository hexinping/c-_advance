
/*


����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:

����: [2,2,1]
���: 1
ʾ�� 2:

����: [4,1,2,1,2]
���: 4

class Solution {
public:
int singleNumber(vector<int>& nums) {

}
};

*/

#include <iostream>
using namespace std;

#include <vector>
#include <map>

//�����㷨 ������map���Ч��
int singleNumber(vector <int> &nums)
{
	int result = 0;
	map <int, int> _map;
	map<int, int> _mapRes;
	bool isCan = false;
	for (int i = 0; i < nums.size();i++)
	{
		int value = nums[i];
		if (_map.find(value) == _map.end())
		{
			//û�оʹ���
			_map[value] = 1;
		}
		else
		{
			//��¼����
			_map[value] = _map[value] + 1;

			//ɾ���ظ�Ԫ��
			_mapRes.erase(value);
		}
		if (_map[value] == 1)
		{
			_mapRes[value] = value;
		}
	}

	map<int, int>::iterator it;
	it = _mapRes.begin();
	result = it->first;
	

	return result;
}

//�����ͬΪ0����ͬΪ1. ���ͬһ�������Σ�ԭ�����䡣
int singleNumber1(vector <int> &nums)
{
	int len = nums.size();
	int result = 0;
	for (int i = 0; i < len; i++){
		result ^= nums[i];
	}
	return result;
}
