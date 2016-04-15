#include <iostream>

class Complex
{
public:
	double real,img;
	Complex(double r) { real = r; img = 2; }
	Complex(const Complex& r)
	{
		std::cout << "Copy Constructor called" << std::endl;
		real = r.real;
		img = 1;
	}
	Complex(int i)
    {
		std::cout << "type transform constructor called" << std::endl;
		real = i;
		img = 0;
	}
	~Complex(){std::cout<<"destructor"<<std::endl;}
};

/* TEST: copy constructor should be called at return
 * TEST Failed ----> not so, need an review
 * Issue fixed: g++ use an optimization here which let no copy constructor be called,
 ********************************************************************************
 ********************************************************************************
 *********** fixed by using g++ -fno-elide-constructors options *****************
 ********source: http://blog.sina.com.cn/s/blog_4ab8464c0100kybj.html************
 *******************************************************************************
 ********************************************************************************/
Complex CopyConstructorReturnTest(double i)
{
	Complex c(i);
	return c;
}

// TEST: copy constructor should be called at parameter transfer
double CopyConstructorFuncCallTest_1(Complex r)
{
	return r.img;
}

// TEST: copy constructor should not be called at call by reference
double CopyConstructorFuncCallTest_2(Complex& r)
{
	return r.img;
}

/* Main TEST */
int main()
{
	Complex r1(7.2);
    // Copy Constructor called here
	Complex r2(r1);


	// Copy Constructor called here, img = 1 rather than 2
	std::cout << CopyConstructorReturnTest(7).img << std::endl;
	// Copy Constructor called here, img = 1 rather than 2
	std::cout << CopyConstructorFuncCallTest_1(r1) << std::endl;
	// No Constructor called at Call by reference, img = 2
	std::cout << CopyConstructorFuncCallTest_2(r1) << std::endl;


	// Type Transform Constructor
	Complex r3 = 12;
	std::cout << r3.real << " " << r3.img << std::endl;
	// Type Transform Constructor
	r2 = 12;
	std::cout << r2.real << " " << r2.img << std::endl;
}
