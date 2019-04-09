
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

#include <iostream>
using namespace std;


/*
思路:
	1 组成两个链表，然后把各自的数相加
	2 最后倒序组成一个新链表

*/

//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//
//};
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};



ListNode * createList(vector<int> vec)
{
	int length = vec.size();
	ListNode *p = nullptr;
	ListNode *s = nullptr;
	ListNode *head = nullptr;
	int count = 0;
	while (length>0)
	{
		s = new ListNode();
		s->val = vec[count];
		if (head == nullptr)
		{
			head = s;
		}
		else
		{
			p->next = s;
		}
		p = s;
		length--;
		count++;
	}
	p->next = nullptr;
	if (nullptr != head)
		cout << "创建成功" << endl;
	else
		cout << "没有数据输入" << endl;
	return head;
}

// 返回链表上数字代表的总数，逆序输出
int getTotalNum(ListNode *p)
{
	int result = 0;
	int count = 0;
	while (p!=nullptr)
	{
		int val = p->val;
		result += (val % 10)* pow(10,count);
		count++;
		p = p->next;
	}
	return result;
}

ListNode *outList(int number)
{
	// 先逆序输出到vector 807->708
	vector<int> vec;
	
	// 方法1:转成sting
	// 方法2:输出每个位上的数字
	int result = 0;
	while (number)
	{
		result = (number % 10);
		vec.push_back(result);
		number /= 10;

	}

	ListNode *p = createList(vec);
	return p;
}