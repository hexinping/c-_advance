#pragma once

#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
	Person(){}
	Person(int age, string name) :m_age(age), m_name(name){}
	~Person(){
		cout << "delete mem>> age:" << m_age << ", name:" << m_name << endl;
	}


	inline bool Person::operator==(const Person &ps) const
	{

		if (this->m_age == ps.m_age && this->m_name == ps.m_name)
			return true;
		return false;
	}

	int m_age;
	string m_name;
};

