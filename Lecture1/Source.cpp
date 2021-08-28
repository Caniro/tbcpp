#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

//#define MY_NUMBER 333

//#define MAX(a, b) (((a)>(b)) ? (a):(b))
//#define LIKE_APPLE

//int add(int a, int b);	// forward declaration

//int addTwoNumbers(int num_a, int num_b)
//{
//	int sum = num_a + num_b;
//	
//	return sum;
//}	
//
//void printHelloWorld()
//{
//	cout << "Hello, World!" << endl;
//}

//namespace MySpace1
//{
//	namespace InnerSpace
//	{
//		int my_function()
//		{
//			return 0;
//		}
//	}
//	int doSomething(int a, int b)
//	{
//		return a + b;
//	}
//}
//
//int doSomething(int a, int b)
//{
//	return a * b;
//}

int main()
{
	//int a(0), b(0);	// a=0, b=0;
	//cout << "Input a : ";
	//cin >> a;
	//cout << "Input b : ";
	//cin >> b;
	//cout << "Sum is : " << addTwoNumbers(a, b) << endl;
	//printHelloWorld();

	//int x(-2);
	//int y =	(x > 0) ? 1 : 2;	// ternary operator
	//cout << y;
	
	/*cout << doSomething(3, 4) << endl;
	cout << MySpace1::doSomething(3, 4) << endl;
	using namespace MySpace1::InnerSpace;
	my_function();*/

	//cout << MAX(1+3, 2) << endl;
	//cout << max(1+3, 2) << endl;		// <algorithm>

//#ifdef LIKE_APPLE
//	cout << "Apple" << endl;
//#endif
//#ifndef LIKE_APPLE
//	cout << "Orange" << endl;
//#endif

#/*ifdef LIKE_APPLE
	cout << "Apple" << endl;
#else
	cout << "Orange" << endl;
#endif*/

	//char chValue = 'A';
	//cout << (int)chValue << endl;
	//auto aValue = 3.141592f;
	//auto aValue2 = 3.141592;
	//cout << aValue << " " << sizeof(aValue) << endl;
	//cout << aValue2 << " " << sizeof(aValue2) << endl;
	
	//int a(1.23);		// direct initialization	/ warning
	//int b{ 1.23 };	// uniform initialization	/ error
	//cout << a << endl;

	//short s = 1;	// 2 bytes = 16 bits
	//cout << pow(2, sizeof(short) * 8-1)-1 << endl;
	//cout << numeric_limits<short>::max() << endl;
	//cout << numeric_limits<short>::min() << endl;		// absolute minimum
	//cout << numeric_limits<short>::lowest() << endl;	// including (-)

	//cout << 22 / 4 << endl;
		
	//int_least64_t fl(5);	// at least 64 bits = 8 bytes.
	
	//int i = 123;
	//float f = 123.456f;
	//void* my_void;		// void pointer, generic pointer
	//my_void = (void*)&i;
	//cout << my_void << endl;
	//my_void = (void*)&f;
	//cout << my_void << endl;
	//cout << *static_cast<float*>(my_void) << endl;	// casting to float
	////cout << my_void + 1 << endl;		// error

	/*float f(123456789.0f);
	cout <<  f << endl;
	cout << std::setprecision(9) << f << endl;
	cout << f << endl;*/

	/*double zero(0.0), posinf(5.0 / zero), neginf(-5.0 / zero), nan(zero / zero);
	cout << posinf << " " << std::isinf(posinf) << endl;
	cout << neginf << " " << std::isnan(neginf) << endl;
	cout << nan << " " << std::isnan(nan) << endl;*/


	return 0;
}

int add(int a, int b)
{
	return a + b;
}