
/*


给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

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

//基础算法 用两个map提高效率
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
			//没有就存下
			_map[value] = 1;
		}
		else
		{
			//记录次数
			_map[value] = _map[value] + 1;

			//删除重复元素
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

//异或：相同为0，不同为1. 异或同一个数两次，原数不变。
int singleNumber1(vector <int> &nums)
{
	int len = nums.size();
	int result = 0;
	for (int i = 0; i < len; i++){
		result ^= nums[i];
	}
	return result;
}
