#include<iostream>
#include<thread>
#define ull unsigned long long
using namespace std;

// Multi threading using function pointer

void Print(ull value)
{
	int count = 0;
	for (auto i = 0; i < value; i++)
		count++;
}

// 1. Using function pointer 
//int main()
//{
//	thread T1(Print,19000000000); 
//	T1.join();
//	return 0;
//}

// 2. Using Lambda function
//int main()
//{
//	auto f = [](int value) //we can directly assign lambda at creation time.
//	{int count = 0;
//	for (auto i = 0; i < value; i++)
//		count++; };
//
//	thread T1(f,19000000000);
//	T1.join();
//	return 0;
//}

// 3. Using Functor
//class thread_obj
//	{
//	public:
//		void operator()(int value)
//		{
//
//		}
//	};
//int main()
//{	
//	thread T1(thread_obj(),19000000000);
//	T1.join();
//	return 0;
//}

// Using non static member function
//class Base
//{
//public:
//	void run(int value)
//	{
//		cout << "Hello World";
//	}
//};
//int main()
//{
//	Base b;
//	thread T1(&Base::run, &b, 100); // add of function, add of object, parameters
//	T1.join();
//	return 0;
//}

//Using Static member function
class Base
{
public:
	static void run(int value)
	{
		cout << "Hello world";
	}
};

int main()
{
	thread T1(&Base::run, 10); // No need to pass object because of static member function
	T1.join();
}