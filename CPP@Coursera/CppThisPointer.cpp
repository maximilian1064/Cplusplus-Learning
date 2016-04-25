/* This pointer
 * each non-static member function has a this pointer which points to the object it deals with.
 * The idea of this pointer comes from the compilation of C++ program. If we translate
 * the C++ program to C program (in early days of C++ the compilation is done by this as the lecture says),
 * then the this pointer serves as an additional argument of the translated member function.(there is only
 * global function in C, such argument is needed to specify the C++ object which this function deals with).
 *
 * This pointer can not be applied on static member functions ("OO global function" by my word XD), as they
 * don't deal with single object. ("OO global") ！！！！！！！
 *
 * This Pointer can be used for returning current object in member function.
 *
 * non-static C++ member function has one more argument, i.e., the this pointer
 */

#include <iostream>

class whatever
{
public:
	int i; // public member here for simplicity
	void print(){std::cout << i << std::endl;}
	whatever what(){std::cout << "this->i: " << this->i << std::endl; return *this;}
	void dummy(){std::cout << "something weird :D" << std::endl; /* std::cout << i <<std::endl; */ }
};

/*C translation of the above class, just to show the origin of this pointer*/
struct Cwhatever
{
	int i;
};

void cprint(Cwhatever* p)
{
	std::cout << p->i << std::endl;
}

int main()
{
	// C++
	whatever we1;
	// public member here for simplicity
	we1.i = 1;
	we1.print();

    // C translation
	Cwhatever we2 = {1};
	cprint(& we2);

	// typical usage of this pointer
	whatever we3;
	we3 = we1.what();

	// something weird, what the crap! null pointer works without bug!
	// (Due to the one-more-argument mechanism of C++ function :D)
	// just dummy things for showing, don't write this !!!!!!!!!!!!!!!
	whatever* p = NULL;
	p->dummy();

	return 0;
}
