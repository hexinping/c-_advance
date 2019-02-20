
#include <iostream>
using namespace std;


#include "example1.h"



int main(int argc, char* argv[])
{

	//example1
	vector<int> ilist = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> result;
	result = twoSum2(ilist,target);

	system("pause");

	return 0;
}