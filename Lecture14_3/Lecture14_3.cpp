
#include <iostream>

using namespace std;

class Exception
{
public:
	virtual void	report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void	report()
	{
		cerr << "Array Exception report" << endl;
	}
};


class MyArray
{
private:
	int	m_data[5];
public:
	int& operator [] (const int& ix)
	{
		if (ix < 0 || ix > 5)
			throw ArrayException();
		return (m_data[ix]);
	}
};

void	doSomething()
{
	MyArray my_array;
	
	try
	{
		my_array[100];
	}
	catch (Exception & e)
	{
		e.report();
	}
	
}

int main()
{
	doSomething();
}