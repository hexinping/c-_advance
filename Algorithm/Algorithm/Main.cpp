
#include <iostream>
using namespace std;


#include "example1.h"
#include "example2.h"
#include "example88.h"
#include "example131.h"
#include "example136.h"
#include "example139.h"
#include "example169.h"
#include "example240.h"


int a = 0;

int testRet()
{
	return a++;  //先返回a 再++，跟= 一样       ++a同理，先++再返回a
}

int main(int argc, char* argv[])
{

	//***************example1

	//vector<int> ilist = { 2, 7, 11, 15 };
	//int target = 9;
	//vector<int> result;
	//result = twoSum2(ilist,target);

	//***************example2

	//vector<int> v1 = { 2, 4, 3};
	//vector<int> v2 = { 5, 6, 4};
	//ListNode *p1 = createList(v1);
	//ListNode *p2 = createList(v2);

	//int sum1 = getTotalNum(p1);
	//int sum2 = getTotalNum(p2);
	//int sum = sum1 + sum2;

	//ListNode * r = outList(sum);


	//***************example136
	//vector<int> vec = { 4, 1, 2, 1, 2 };
	//int result = singleNumber1(vec);

	
	//***************example169
	//vector<int> vec = { 3, 2, 3 };
	//int result = majorityElement(vec);


	//***************example240

	//vector<vector<int>> matrix = {
	//	{ 1, 4, 7, 11, 15 },
	//	{ 2, 5, 8, 12, 19 },
	//	{ 3, 6, 9, 16, 22 },
	//	{ 10, 13, 14, 17, 24},
	//	{ 18, 21, 23, 26, 30}
	//};
	//
	//bool result = searchMatrix(matrix, 5);

	//system("pause");

	//***************example88
	//std::vector<int> nums1 = { 1, 2, 3, 9,1,45,0, 0, 0 };
	//std::vector<int> nums2 = { 2, 5, 6 };
	//std::vector<int> result = merge(nums1, 6, nums2, 3);


	//***************example139

	//string mainStr = "applepenapple";
	//vector<string> wordDict = {"apple", "pen" };
	//bool   result = wordBreak(mainStr, wordDict);


	//***************example131

	for (int i = 0; i < 10;i++)
	{
		int j = testRet();
		cout << "j===========" << j << endl;
	}


	return 0;
}