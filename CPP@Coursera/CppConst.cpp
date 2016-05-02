/*
 * Const Keyword
 *
 *
 * Const keyword can be placed before an object to forbid modifications of this object.
 *
 * For const object the corresponded const member function is needed. The const member function
 * has such form:  ---- void foo() const {} ----
 *
 * For a const object only the const member function can be used (static member function can also
 * be used because it is not related to any object, also static member variable can be modified.
 * "OO global")
 *
 * In a const member function also no non-const member function can be called because they can modify
 * the object, here static members are exceptions though.
 *
 * Typical applications: const reference as argument of "Call by Reference"
 *                       void foo (const sample& o);
 *
 * Something special: "void foo (const sample& o) const" and
 *                    "void foo (const sample& o)"
 *                    is not a repeated definition !!!!!!!!!
 */

#include <iostream>

class sample
{
public:
	// public member for simplicity of testing
	int i;
	static int nSample;

	// two foo1, not repeated defintion due to "const"
	void foo1() { std::cout << "foo1 called" << std::endl; }
	void foo1() const;
    static void foo2() { std::cout << "static foo2 called by const foo1" << std::endl; }
    void foo4() {}
};

void sample::foo1() const
{
	std::cout << "const foo1 called" << std::endl;

	// no problem calling static members in const members
	this->foo2();
	std::cout << "nSample = " << this->nSample << std::endl;

	// this->i = 1; // error code
	// foo4(); // error code
}



// Applications: Call by Const Reference
void foo3(const sample& s)
{
    s.foo1();
    // s.foo4();
}

int sample::nSample = 1;

int main()
{
	sample s1;
	sample::nSample ++;
    foo3(s1);
    s1.foo1();
    // const sample s2;
    // s2.i = 1; // error code


	return 0;
}
