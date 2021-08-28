#include <iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		return (this);
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis()
	{
		return (this);
	}
};

int main()
{
	B b;
	A& ref = b;

	ref.print();
	ref.getThis()->print();

}
