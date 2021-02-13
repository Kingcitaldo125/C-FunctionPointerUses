#include <iostream>
#include <functional>
#include <thread>


using std::cout;
using std::endl;


class MyFoo
{
public:
	void thingg(int a, int b)
	{
		cout << "a+b= " << a + b << endl;
	}
};


class MyBar
{
public:
	void thingg(int a, int b)
	{
		cout << "a+b= " << a + b << endl;
	}

	void(MyBar::*x)(int, int);
};


int main()
{
	std::thread th(&MyFoo::thingg, MyFoo(), 2,3);
	th.join();

	MyBar bar;

	bar.x = &MyBar::thingg;

	(bar.*(bar.x))(2,3);

	cout << "Hello World" << endl;

	return 0;
}
