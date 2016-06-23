/*
 * STL std::vector & OL & "deep"(functional) copy & dynamic memory allocation:
 *
 *
 * Self implementation of  STL std::vector (data type: int, too expensive to implement the template XD)
 * using the principle of Overloading and dynamic memory allocation and "deep" copy.
 *
 * Quasi like the last stuff, i.e. self implementation of STL std::string using the overloading of "=" operator.
 *
 * 0. Features:
 * 		---- push_back()
 * 		---- a1 = a2
 * 		---- MyVector a1(a2)
 * 		---- length()
 * 		---- a1 = a2 (int a2[5] =... )
 * 		---- a1[i] = 5;
 *
 * 1. Something about the dynamic memory allocation:
 *
 *
 */

#include <iostream>
#include <cstring>

#define naive

class MyVector
{
private:
	unsigned int m_length;
	unsigned int m_alloSize;
	int* m_ptr;

public:

	MyVector(): m_length(0),m_alloSize(0),m_ptr(NULL) {}
	MyVector(const MyVector& v);
	~MyVector() { if(m_ptr) delete [] m_ptr; }

	MyVector& operator=(const MyVector& v);
	int& operator[](unsigned int i) { return m_ptr[i]; }
	void push_back(int c);
	unsigned int length() { return m_length; }
};


MyVector::MyVector(const MyVector& v)
{
	m_length = v.m_length;
	m_alloSize = v.m_alloSize;
	m_ptr = new int[m_alloSize];
	memcpy(m_ptr, v.m_ptr, sizeof(int) * m_length);
}


MyVector& MyVector::operator=(const MyVector& v)
{

	/*
	 * for dummy a=a assignment
	 */
	if(m_ptr == v.m_ptr)
		return *this;

	/*
	 * cannot copy memory with NULL pointer!
	 *
	 * whenever you want to change the pointer and its content, which is assigned previously with DMA,
	 * you should manually release the memory allocated first or they will become garbage. Only "delete"
	 * can get the "newed" memory back!!!
	 *
	 * here as the m_ptr is either NULL or "newed", we should do the above things
	 * (NULL pointer has no content, never delete them!!!)
	 */
	if(v.m_length == 0)
	{
		m_length = 0;
		m_alloSize = 0;
		if(m_ptr)
			delete [] m_ptr;
		m_ptr = NULL;
		return *this;
	}

	/*
	 * normal case
	 */
	if(m_alloSize < v.m_length)
	{
		if(m_ptr)
			delete [] m_ptr;
		// faster content copy at a cost of larger memory allocation size
		m_alloSize = 2*v.m_length;
		m_ptr = new int[m_alloSize];
	}
	memcpy(m_ptr, v.m_ptr, sizeof(int) * v.m_length);
	m_length = v.m_length;
	return *this;
}


void MyVector::push_back(int c)
{

	m_length ++;

	if(m_alloSize < m_length)
	{
		int* temPtr;
		if(m_ptr)
		{
#ifdef naive
			m_alloSize = m_length;
#else
			m_alloSize = 2*(m_length-1); // proven to be much faster than the naive way, and is of course better for the RAM XD
#endif
			temPtr = new int[m_alloSize];
			memcpy( temPtr, m_ptr, sizeof(int) * (m_length-1) );
			temPtr[m_length-1] = c;
			delete [] m_ptr;
			m_ptr = temPtr;
		}
		else
		{
			m_alloSize = 2;
			m_ptr = new int[m_alloSize];
			m_ptr[0] = c;
		}
	}
	else
	{
		m_ptr[m_length-1] = c;
	}

}


int main()
{

	MyVector v1;
	for(unsigned int i=0; i<100024; i++)
		v1.push_back(i);
	for(unsigned int i=100000; i<100024; i++)
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	MyVector v2(v1);
	v2[0] = 100;
	for(unsigned int i=0; i<24; i++)
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	MyVector v3;
	v3 = v1;
	for(unsigned int i=1000; i<1024; i++)
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	MyVector v4;
	v3 = v4;
	std::cout << v3.length() << std::endl;


	return 0;
	/* WHAT THE CRAP!!
	 * The following static memory allocation works in quasi dynamicly manner!!!
	 * Then What is the meaning of "new" and dynamic memory allocation???
	 * (Through indeed in the following case we should use "new" and DMA)

	int i;
	std::cin >> i;
	int a[i];
	for(int j=0; j<i; j++)
	{
		a[i] = j;
		std::cout << a[i] << std::endl;
	}
	*/
}
