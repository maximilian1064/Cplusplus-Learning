#include <iostream>

//int a = 0;
int s = 0;

int dummy_func(int a)
{
	lab:
	if(a == 0)
		return 1;
	else
	{
		a = a-1;
		goto lab;
	}
}

int fact( int n )
{
    if ( n == 0 )
       return 1 ;
    else
       return fact( n - 1 ) * n ;
}

int main()
{
    //dummy_func();
	int l = fact(4);
    std::cout << l << std::endl;
	return 0;
}
