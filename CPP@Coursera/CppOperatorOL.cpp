/*
 * Operator Overloading
 *
 * 1. Operator Overloading:
 *    The idea of operator overloading is based on function overloading.
 *    Form:    Type operator+ (arguments)  ---->  #Operands = #Arguments
 *             Type class::operator+ (arguments) ---->  #Operands = #Arguments+1,
 *             as the object already serves as an operand, A+B ----> A.operator+(B)
 * 2. Overloading of "=", sort of important stuff !!!
 *
 */

#include <iostream>

class Ccomplex
{
private:
	int real,image;
public:
	Ccomplex(int a, int b): real(a), image(b) {}
	Ccomplex operator+ (const Ccomplex& c);
	void CcomplexPrint () { std::cout << real << "+" << image << "i" << std::endl; }
	// friend is awesome !!!
	friend Ccomplex operator- (const Ccomplex& c1, const Ccomplex& c2);
};

Ccomplex Ccomplex::operator+ (const Ccomplex& c)
{
	std::cout << "member function" << std::endl;
    return Ccomplex(real + c.real, image + c.image);
}

Ccomplex operator- (const Ccomplex& c1, const Ccomplex& c2)
{
	std::cout << "normal function" << std::endl;
	// c1.CcomplexPrint();
	// the compiler will treat this as modify of the const argument,
	// who knows what happens in this member function?????
    return Ccomplex(c1.real-c2.real, c1.image-c2.image);
}

int main()
{
	Ccomplex c1(3,4), c2(4,5);
	Ccomplex c3 = c1 + c2;
	c2 = c1 - c3;
	c1.CcomplexPrint();
	c2.CcomplexPrint();
	c3.CcomplexPrint();
	return 0;
}
