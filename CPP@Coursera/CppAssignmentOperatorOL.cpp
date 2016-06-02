/*
 * Overloading of the assignment operator ("=") & the importance of "deep copy"
 *
 * 1. The assignment operator can only be overloaded as a member function!!!
 * 2. Being used in the assignment between different types. Should be the basis of many
 *    C++ STL Class, e.g., the std::string class.
 *    char name[] = "peter";
 *    std::string str = name;
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

