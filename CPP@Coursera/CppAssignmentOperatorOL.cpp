/*
 * Overloading of the assignment operator ("=") & the importance of "deep copy"
 *
 *
 *
 * 1. The assignment operator can only be overloaded as a member function!!!
 *
 *
 * 2. Being used in the assignment between different types.
 *    Should be the basis of many C++ STL Class, e.g., the std::string class.
 *    -- char name[] = "peter";
 *    -- std::string str = name;
 *
 *
 * 3. The return type of the operator= function:
 *
 *	  A principle -> keeping the properties of the original '=' operator
 *	  i.e. something like a=b=c / (a=b)=c, if we use void as return type here,
 *	  such expression is not allowed, which is against the property of original '=',
 *	  so we should better use type& here.
 *
 *	  The return type doesn't have any effects on single assignment like "a=b",
 *	  it will be only important if we use the assignment expression as arguments ->
 *	  -- foo(a=b);
 *	  -- c = (a=b);
 *	  -- (a=b) = c;
 *	  So again, better use type& to keep the original property of "=", especially when doing copy.
 *
 *	  For assignment between different types, should consider the specific application of the overloading.
 *	  -- char* Mystring::operator= (char* str);
 *	  -> Mystring a; Mystring b; Char c[];
 *	     a=(b=c);
 *	  -- Mystring& Mystring::operator= (char* str) {...; return *this;}
 *	  -> Mystring a; char b[]; char c[];
 *	     (a=b)=c;
 *
 *
 * 4. "deep" vs. "shallow" copy (functional vs. naive):
 *
 */

#include <iostream>
#include <string>

int main()
{
	std::string str;
	char* name;
	char name2[] = "waht";
	name = name2;
	str = name2;
	std::cout << str << std::endl;

	return 0;
}

