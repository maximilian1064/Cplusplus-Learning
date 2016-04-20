/*
 * Destructor can be used for the return of memory space which are manually allocated to an object by users,
 * for example, usage of "new" keyword in a constructor
 */
#include <iostream>

class DesTest
{
public:
	DesTest(int i){ id = i; std::cout << "Constructor, id=" << id << std::endl; }
	~DesTest(){ std::cout << "Destructor, id=" << id << std::endl; }
private:
	int id;
};

class DesTest2
{
public:
	~DesTest2(){ std::cout << "Destructed!!!" << std::endl; }
};

DesTest d0(0);

void foo()
{
/*
 * some other issue: (*********need to be verified later!!!**********)
 * static VS global ->
 * in a scope VS out of any scope
 * active til program end VS active til program end
 */
	static DesTest d4(4);
	DesTest d5(5);
}

int main()
{
	DesTest2* p2 = new DesTest2[6];
	delete [] p2;
	DesTest* p1 = new DesTest(1);
	//DesTest* p2 = new DesTest[2];
	delete p1;
	//delete [] p2;
	DesTest d2(2);
	foo();
	{DesTest d6(6); static DesTest d7(7);}
	DesTest d8(8);
	double i = 9.0;
	d8 = i;
	std::cout << "end main" << std::endl;
	return 0;
}
