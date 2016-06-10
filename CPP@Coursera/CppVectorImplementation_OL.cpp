/*
 * STL std::vector & OL & "deep"(functional) copy & dynamical memory allocation:
 *
 *
 * Self implementation of  STL std::vector (data type: int, too expensive to implement the template XD)
 * using the principle of Overloading and dynamical memory allocation and "deep" copy.
 *
 * Quasi like the last stuff, i.e. self implementation of STL std::string using the overloading of "=" operator.
 *
 * 1. Something about the dynamical memory allocation:
 *
 *
 */

#include <iostream>

int main()
{
	/* WHAT THE CRAP!!
	 * The following static memory allocation works in quasi dynamically manner!!!
	 * Then What is the meaning of "new" and dynamical memory allocation???
	 * (Through indeed in the following case we should use "new" and DMA)
	 */
	int i;
	std::cin >> i;
	int a[i];
	for(int j=0; j<i; j++)
	{
		a[i] = j;
		std::cout << a[i] << std::endl;
	}

	return 0;
}
