
#include <iostream>
using namespace std;

#include "Person.h"

#include <vector>
#include <list>
#include <map>

/*


	remove/erase/clear
	测试stl容器释放元素时是否自动释放所存元素对应的内存
	{
		ObjA ----》 ObjA1
		元素为对象: 存对象时每次插入、读取以及删除都是操作的执行拷贝构造函数之后的对象，原始对象内存不会被释放
		{
			vector:		pop_back,erase, clear	ObjA1都会自动调用对象的析构函数，ObjA不会被释放
			lsit:		remove,erase, clear		ObjA1都会自动调用对象的析构函数，ObjA不会被释放
			map:		erase, clear			ObjA1都会自动调用对象的析构函数，ObjA不会被释放
		}
		元素为指针
		{
			vector:		pop_back,erase, clear	不会自动调用指针指向对象的析构函数，需要手动调用delete
			lsit:		remove,erase, clear	    不会自动调用指针指向对象的析构函数，需要手动调用delete
			map:		erase, clear			不会自动调用指针指向对象的析构函数，需要手动调用delete
		}
		
	}


	总结：
		存对象和存指针都不会释放内存
		{
			存对象时每次插入读取以及删除都是操作的执行拷贝构造函数之后的对象，原始对象内存不会被释放
			存指针也不会指针指向对象的内存
		}
*/

int main(int argc, char* argv[])
{
	//cout << "test==========" << endl;

	////////////////////////////////////////////////////元素为对象
	Person p(29, "hexinping");
	// A vector测试
	//vector<Person> vec;
	//vec.push_back(p);

	//vec.pop_back();  //会自动调用对象的析构函数

	//vector<Person>::iterator itVect = vec.begin();
	//for (; itVect != vec.end(); ++itVect) {
	//	if (itVect->m_name == "hexinping") {
	//		vec.erase(itVect); //会自动调用对象的析构函数
	//		break;
	//	}
	//}

	//vec.clear(); // 会自动调用对象的析构函数


	//*********************************
	// B list测试
	//list<Person> listP;
	//listP.push_back(p);

	//对象删除需要重载==方法，指针不需要
	//listP.remove(p); // 会自动调用对象的析构函数
	
	//list<Person>::iterator itList = listP.begin();
	//for (; itList != listP.end(); ++itList) {
	//	if (itList->m_name == "hexinping") {
	//		listP.erase(itList); //会自动调用对象的析构函数
	//		break;
	//	}
	//}

	//listP.clear(); //会自动调用对象的析构函数

	//*********************************
	// C map测试
	//map<int, Person> mapP;
	//mapP[1] = p;

	//map<int,Person>::iterator itMap = mapP.begin();
	//for (; itMap != mapP.end(); ++itMap) {
	//	if (itMap->second.m_name == "hexinping") {
	//		mapP.erase(itMap); //会自动调用对象的析构函数
	//		break;
	//	}
	//}

	//mapP.clear(); //会自动调用对象的析构函数


	////////////////////////////////////////////////////元素为指针
	Person *pc = new Person(29, "hexinping");

	// A vector测试
	//vector<Person*> vec;
	//vec.push_back(pc);

	//vec.pop_back();  //不会自动调用指针指向对象的析构函数

	//vector<Person*>::iterator itVect = vec.begin();
	//for (; itVect != vec.end(); ++itVect) {
	//	if ((*itVect)->m_name == "hexinping") {
	//		delete *itVect;    //需要手动调用删除delete操作，必须先删除在释放容器元素
	//		vec.erase(itVect); //不会自动调用指针指向对象的析构函数
	//		break;
	//	}
	//}

	//vec.clear(); // 不会自动调用指针指向对象的析构函数


	// B list测试
	//list<Person *> listP;
	//listP.push_back(pc);
	//如果是指针就不需要重载==操作符
	//listP.remove(pc);   // 不会自动调用指针指向对象的析构函数

	//list<Person*>::iterator itList = listP.begin();
	//for (; itList != listP.end(); itList++)
	//{
	//	//先用解引用获取指针(*itList)
	//	if ((*itList)->m_name=="hexinping")
	//	{
	//		delete (*itList);
	//		listP.erase(itList); // 不会自动调用指针指向对象的析构函数
	//		break;
	//	}
	//}

	//listP.clear(); // 不会自动调用指针指向对象的析构函数



	// C map测试

	map<int, Person*> mapP;
	mapP[1] = pc;
	//map<int,Person*>::iterator itMap = mapP.begin();
	//for (; itMap != mapP.end(); ++itMap) {

	//	if (itMap->second->m_name == "hexinping") {
	//		delete (itMap->second);
	//		mapP.erase(itMap); // 不会自动调用指针指向对象的析构函数
	//		break;
	//	}
	//}

	//mapP.clear(); //会自动调用对象的析构函数

	system("Pause");
	return 0;
}