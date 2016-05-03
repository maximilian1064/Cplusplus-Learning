/*
 * C++ @ Coursera: Assignment 1 week 3
 * passed POJ, compile error on Coursera (what the crap!!!) XD
 *
 * Something new here:
 * Return by reference <-> ( Call by reference )
 * With this return type, the pointer of the return arguments is implicitly returned.
 * So we can now manipulate the return value of an function, this makes the code clearer.
 * (pointer is annoying for sure)
 *
 * Because the return value is a reference, we can now put the function call on the left of
 * an assignment :-D, sort of cool.
 *
 * -- int i; // global
 * -- int& foo() { return i; }
 * -- foo() = 5;
 * -- std::cout << foo() << std::endl;
 *
 * Take care of the scope of the variable when using Return by Reference !!!!
 * i.e. the variable must be active in the scope where the function is called
 * as well as in that function, foo1(), foo2() in the following example may show
 * two possibilities for that.
 *
 * Some review on reference: the reference can replace the original var almost anywhere ???
 *
 * ----Definition of reference: A reference variable is an alias, that is, another name for
 * ----an already existing variable. Once a reference is initialized with a variable, either
 * ----the variable name or the reference name may be used to refer to the variable.
 *
 * useful sources for this topic:
 * -- http://www.tutorialspoint.com/cplusplus/cpp_references.htm
 * -- http://www.tutorialspoint.com/cplusplus/returning_values_by_reference.htm
 */
#include <iostream>

class A
{
public:
    int val;
    A() { val = 0; }
    A(int i) { val = i; }
    A& GetObj() { return *this; }
};

int i;
// sort of dummy function, why not just use i -_-#
int& foo1() { return i; }

// dummy function to test Call by reference
double& foo2(double& i) { return i; }

int main()
{
    A a;
    std::cout << a.val << std::endl;
    a.GetObj() = 5;
    std::cout << a.val << std::endl;


    // return by reference
    foo1() = 6;
    std::cout << foo1() << std::endl;


    double k;
    // dummy -_-#, same as k = 7
    foo2(k) = 7;
    std::cout << k << std::endl;


    // review tests on reference
    A& b = a;
    std::cout << b.val << std::endl;


    return 0;
}
