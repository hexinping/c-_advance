
/*
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

*/

#include <iostream>
using namespace std;


/*
˼·:
	1 �����������Ȼ��Ѹ��Ե������
	2 ��������һ��������

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
		cout << "�����ɹ���" << endl;
	else
		cout << "û���������룡" << endl;
	return head;
}

// �������������ִ�����������������
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
	// �����������vector 807->708
	vector<int> vec;
	
	// ����1:ת��sting
	// ����2:���ÿ��λ�ϵ�����
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