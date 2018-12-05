#include "Main.h"
#include <iostream>

using namespace std;


//函数模板
template <typename T>
bool equivalent(const T &a, const T &b)
{
	return !(a < b) && !(b < a);
}


//类模板
template<typename T = int>
class bigNumber
{
public:
	T _v;

	bigNumber(T a) :_v(a){};
	inline bool operator<(const bigNumber&b)const;
};

// 在类模板外实现成员函数
template<typename T>
bool bigNumber<T>::operator<(const bigNumber& b) const{
	return _v < b._v;
}

void test1()
{

	/*
	关于模板（函数模板、类模板）的模板参数（详见文献[1]第3章）：

	类型参数（type template parameter），用 typename 或 class 标记；
	非类型参数（non-type template parameter）可以是：整数及枚举类型、对象或函数的指针、对象或函数的引用、对象的成员指针，非类型参数是模板实例的常量；
	模板型参数（template template parameter），如“template<typename T, template<typename> class A> someclass {};”；
	模板参数可以有默认值（函数模板参数默认是从 C++11 开始支持）；
	函数模板的和函数参数类型有关的模板参数可以自动推导，类模板参数不存在推导机制；
	*/

	bigNumber<> a(1), b(1); // 使用默认参数，"<>"不能省略

	cout << equivalent(a, b) << endl;
	cout << equivalent<double>(1, 2) << endl;
}

//模板特例化之前先声明模板通例
template<typename T, int N>
class Vec
{
public:
	T _v[N];
	// ... // 模板通例（primary template），具体实现
};

template<> /********************************** 模板特例化******************/
class Vec < float, 4 > {
	float _v[4];
	// ... // 对 Vec<float, 4> 进行专门实现，如利用向量指令进行加速
};
template<int N>
class Vec < bool, N > {
	char _v[(N + sizeof(char) - 1) / sizeof(char)];
	// ... // 对 Vec<bool, N> 进行专门实现，如用一个比特位表示一个bool
};

void test2()
{
	//模板特例化
	/*
		所谓模板特例化即对于通例中的某种或某些情况做单独专门实现，最简单的情况是对每个模板参数指定一个具体值，这成为完全特例化（full specialization），
		另外，可以限制模板参数在一个范围取值或满足一定关系等，这称为部分特例化（partial specialization），
		用数学上集合的概念，通例模板参数所有可取的值组合构成全集U，完全特例化对U中某个元素进行专门定义，部分特例化对U的某个真子集进行专门定义。

		关于模板特例化（详见文献[1]第4章）：

		&&&&&&&&&&&&&&&&&&在定义模板特例之前必须已经有模板通例（primary template）的声明；&&&&&&&&&&&&&&&&&&&&&&
		模板特例并不要求一定与通例有相同的接口，但为了方便使用（体会特例的语义）一般都相同；
		匹配规则，在模板实例化时如果有模板通例、特例加起来多个模板版本可以匹配，则依据如下规则：对版本AB，如果 A 的模板参数取值集合是B的真子集，则优先匹配 A，如果 AB 的模板参数取值集合是“交叉”关系（AB 交集不为空，且不为包含关系），则发生编译错误，对于函数模板，用函数重载分辨（overload resolution）规则和上述规则结合并优先匹配非模板函数。

	*/

}

/*
	无论是函数模板还是类模板，在实际代码中看起来都是“千变万化”的。这些“变化”，主要是因为类型被当做了参数，导致代码中可以变化的部分更多了。

	归根结底，模板无外乎两点：

	1 函数或者类里面，有一些类型我们希望它能变化一下，我们用标识符来代替它，这就是“模板参数”；

	2 在需要这些类型的地方，写上相对应的标识符（“模板参数”）。

	当然，这里的“可变”实际上在代码编译好后就固定下来了，可以称之为编译期的可变性。

	这里多啰嗦一点，主要也是想告诉大家，模板其实是个很简单的东西。

*/



template <typename T>
class vector
{
public:
	void clear()
	{
		// 函数内部实现
	}

	void clear2();

private:

	T *elemects;

};


template<typename T>
void vector<T>::clear2()
{
	//函数外部实现
}

//觉得模板类的使用就是多了一个<T>, 比如声明一个vector对象，就用 vector<T> vec;




//模板函数  <typename T> 这个叫模板参数 （）==》参数
template <typename T> void foo(T const &v);
template <typename T> T foo();
template <typename T, typename U> U foo(T const&);
template <typename T>
void foo()
{
	T var;
}


/*

	1.2.2 模板函数的使用
	我们先来看一个简单的函数模板，两个数相加：

	template <typename T> T Add(T a, T b)
	{
		return a + b;
	}
	函数模板的调用格式是：

	***************** 函数模板名 < 模板参数列表 > ( 参数 ) *******************

	*/


template <typename T> T Add(T a, T b)
{
	return a + b;
}


float data[1024];

template <typename T> T GetValue(int i)
{
	return static_cast<T>(data[i]);
}


template <typename SrcT, typename DrcT> DrcT c_style_cast(SrcT v)
{
	return (DrcT)v;
}


template <int i> class A {};

int main(int argc, char* argv[])
{
	test1();
	test2();


	int a = 5;
	int b = 3;
	int result = Add<int>(a, b);

	printf("result=%d \n",result);

	float a1 = GetValue<float>(0);	
	int b1 = GetValue<int>(1);	

	int v = 0;
	float i = c_style_cast<int, float>(v);

	int x = 3;
	A<5> a_; // 正确！

	

	system("pause");

	return 0;
}

