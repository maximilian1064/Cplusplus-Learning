/*
 * - the static member is shared by all objects in program, not only for an certain object.
 *   it is sort of global variable/functions, but for OO programming it is important to pack
 *   such global variable/functions in an class which they are related to. So, these things are
 *   for OO.
 * - application example: count the number of certain type objects in program.
 * - predefinition in the file contain the class to avoid link error?
 *
 * - static member should be some important stuff in C++
 */

#include <iostream>
#include "CRectangle.h"

/*predeclaration, just like an global variable,
 *static member variable is sort of pseudo global variable XD
 */
int	CRectangle::totalNumber = 0;
int CRectangle::totalArea = 0;

void foo(CRectangle r)
{
	std::cout << "foo called" << std::endl;
}

int main()
{
	CRectangle r1(1);
	CRectangle r2 = r1;
	CRectangle r3(2);
	double i = 5.0;
	r3 = i;
	foo(r3);
	CRectangle::printTotal();
	return 0;
}
