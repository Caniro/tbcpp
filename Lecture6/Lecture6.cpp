#include <iostream>
#include <vector>

int fibo(int x)
{
	int a, b, c, y;

	if (x == 0)
	{
		std::cout << 0 << std::endl;
		return (0);
	}
	if (x == 1)
	{
	std::cout << 1 << std::endl;
	return (0);
	}
	a = 0;
	b = 1;
	y = 1;
	while (++y <= x)
	{
		c = a + b;
		a = b;
		b = c;
	}
	std::cout << c << std::endl;
	return (c);
}

int main()
{
	using namespace std;
	
	//vector<int> arr { 1,2,3,4,5 };
	//for (auto &itr : arr)
	//	cout << itr << " ";
	//cout << endl;
	//cout << &arr << endl;
	//arr.resize(10);
	//for (auto& itr : arr)
	//	cout << itr << " ";
	//cout << endl;
	//cout << &arr << endl;
	//arr.resize(2);
	//for (auto& itr : arr)
	//	cout << itr << " ";
	//cout << endl;
	//cout << &arr << endl;

	for (int i = 0; i < 10; i++)
		fibo(i);
	return 0;
}
