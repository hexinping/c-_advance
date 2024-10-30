
#include <iostream>
using namespace std;

#include "Person.h"

#include <vector>
#include <list>
#include <map>

/*


	remove/erase/clear
	����stl�����ͷ�Ԫ��ʱ�Ƿ��Զ��ͷ�����Ԫ�ض�Ӧ���ڴ�
	{
		ObjA ----�� ObjA1
		Ԫ��Ϊ����: �����ʱÿ�β��롢��ȡ�Լ�ɾ�����ǲ�����ִ�п������캯��֮��Ķ���ԭʼ�����ڴ治�ᱻ�ͷ�
		{
			vector:		pop_back,erase, clear	ObjA1�����Զ����ö��������������ObjA���ᱻ�ͷ�
			lsit:		remove,erase, clear		ObjA1�����Զ����ö��������������ObjA���ᱻ�ͷ�
			map:		erase, clear			ObjA1�����Զ����ö��������������ObjA���ᱻ�ͷ�
		}
		Ԫ��Ϊָ��
		{
			vector:		pop_back,erase, clear	�����Զ�����ָ��ָ������������������Ҫ�ֶ�����delete
			lsit:		remove,erase, clear	    �����Զ�����ָ��ָ������������������Ҫ�ֶ�����delete
			map:		erase, clear			�����Զ�����ָ��ָ������������������Ҫ�ֶ�����delete
		}
		
	}


	�ܽ᣺
		�����ʹ�ָ�붼�����ͷ��ڴ�
		{
			�����ʱÿ�β����ȡ�Լ�ɾ�����ǲ�����ִ�п������캯��֮��Ķ���ԭʼ�����ڴ治�ᱻ�ͷ�
			��ָ��Ҳ����ָ��ָ�������ڴ�
		}
*/

void STLTest()
{
	//cout << "test==========" << endl;

	////////////////////////////////////////////////////Ԫ��Ϊ����
	Person p(29, "hexinping");
	// A vector����
	//vector<Person> vec;
	//vec.push_back(p);

	//vec.pop_back();  //���Զ����ö������������

	//vector<Person>::iterator itVect = vec.begin();
	//for (; itVect != vec.end(); ++itVect) {
	//	if (itVect->m_name == "hexinping") {
	//		vec.erase(itVect); //���Զ����ö������������
	//		break;
	//	}
	//}

	//vec.clear(); // ���Զ����ö������������


	//*********************************
	// B list����
	//list<Person> listP;
	//listP.push_back(p);

	//����ɾ����Ҫ����==������ָ�벻��Ҫ
	//listP.remove(p); // ���Զ����ö������������

	//list<Person>::iterator itList = listP.begin();
	//for (; itList != listP.end(); ++itList) {
	//	if (itList->m_name == "hexinping") {
	//		listP.erase(itList); //���Զ����ö������������
	//		break;
	//	}
	//}

	//listP.clear(); //���Զ����ö������������

	//*********************************
	// C map����
	//map<int, Person> mapP;
	//mapP[1] = p;

	//map<int,Person>::iterator itMap = mapP.begin();
	//for (; itMap != mapP.end(); ++itMap) {
	//	if (itMap->second.m_name == "hexinping") {
	//		mapP.erase(itMap); //���Զ����ö������������
	//		break;
	//	}
	//}

	//mapP.clear(); //���Զ����ö������������


	////////////////////////////////////////////////////Ԫ��Ϊָ��
	Person* pc = new Person(29, "hexinping");

	// A vector����
	//vector<Person*> vec;
	//vec.push_back(pc);

	//vec.pop_back();  //�����Զ�����ָ��ָ��������������

	//vector<Person*>::iterator itVect = vec.begin();
	//for (; itVect != vec.end(); ++itVect) {
	//	if ((*itVect)->m_name == "hexinping") {
	//		delete *itVect;    //��Ҫ�ֶ�����ɾ��delete������������ɾ�����ͷ�����Ԫ��
	//		vec.erase(itVect); //�����Զ�����ָ��ָ��������������
	//		break;
	//	}
	//}

	//vec.clear(); // �����Զ�����ָ��ָ��������������


	// B list����
	//list<Person *> listP;
	//listP.push_back(pc);
	//�����ָ��Ͳ���Ҫ����==������
	//listP.remove(pc);   // �����Զ�����ָ��ָ��������������

	//list<Person*>::iterator itList = listP.begin();
	//for (; itList != listP.end(); itList++)
	//{
	//	//���ý����û�ȡָ��(*itList)
	//	if ((*itList)->m_name=="hexinping")
	//	{
	//		delete (*itList);
	//		listP.erase(itList); // �����Զ�����ָ��ָ��������������
	//		break;
	//	}
	//}

	//listP.clear(); // �����Զ�����ָ��ָ��������������



	// C map����

	map<int, Person*> mapP;
	mapP[1] = pc;
	//map<int,Person*>::iterator itMap = mapP.begin();
	//for (; itMap != mapP.end(); ++itMap) {

	//	if (itMap->second->m_name == "hexinping") {
	//		delete (itMap->second);
	//		mapP.erase(itMap); // �����Զ�����ָ��ָ��������������
	//		break;
	//	}
	//}

	//mapP.clear(); //���Զ����ö������������
}

void TestStuctMemSzie()
{
	struct student {
		int num;
		char name[20];
		char gender;
	};
	student s = { 10, "asd", 'M' };
	cout << s.num << endl;
	cout << sizeof(s.num) << endl;
	/*
	sizeof(s.name)�������name������ܴ�С������������ĵ���Ԫ�صĴ�С��
	name��һ��char[20]���飬ռ��20���ֽڣ�ÿ��charռ1�ֽڣ�20��char�ܹ�20�ֽڣ�����ˣ�sizeof(s.name)����20
	*/
	cout << sizeof(s.name) << endl;
	cout << sizeof(s.gender) << endl;
	cout << sizeof(s) << endl;
}
int main(int argc, char* argv[])
{
	//STLTest();
	TestStuctMemSzie();
	system("Pause");
	return 0;
}