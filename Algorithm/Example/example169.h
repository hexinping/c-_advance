/*

给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2


class Solution {
public:
int majorityElement(vector<int>& nums) {

}
};


*/


#include <iostream>
using namespace std;

#include <vector>
#include <map>



int majorityElement(vector<int>& nums)
{
	int size = nums.size();
	int com = size / 2;

	int result = 0;
	map <int, int> _map;
	bool isCan = false;
	for (int i = 0; i < nums.size(); i++)
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
		}

		if (_map[value]>com)
		{
			result = value;
			break;
		}
		
	}
	return result;
}

