/*
 * C++ Friend (function,member function,class)
 * in C++ Friend is used for the access of a function!!! or all functions!!! of a class
 * to the private member of another class,
 * as the friend of an class they can access the private member of that class
 */

#include <iostream>


class human;

class monkey
{
private:
	int nBanana;
	int nApple;
	void whatever(){std::cout << "whatever!" << std::endl;}
friend class human;
public:
	monkey(int i, int j){ nBanana = i; nApple = j; }
	void carGetting(human h[], int nHuman);
};

class human
{
private:
	int nCar;
	int nHouse;
friend void monkey::carGetting(human h[], int nHuman);
public:
	human(int i, int j=1){ nCar = i; nHouse = j; }
	void bananaGetting(monkey m);
};

void monkey::carGetting(human h[], int nHuman)
{
	for(int i=0;i<nHuman;i++)
	{
		std::cout << "-monkey: my human friend " << i+1 << " give me " << h[i].nCar << " cars" << std::endl;
	}
    std::cout << "-monkey: I'm a happy monkey, LOL" << std::endl;
}

void human::bananaGetting(monkey m)
{
	std::cout << "human: my monkey friend give me " << m.nBanana << " bananas"
			  << " and " << m.nApple << " apples"
			  << " in exchange of my cars"
			  << std::endl
			  << "    I'm happy, LOL, XD"
			  << std::endl;
	m.whatever();
}

int main()
{
	human h[3] = {human(2), human(3), human(1)};
	monkey monkeyKing(5,5);
	monkeyKing.carGetting(h, sizeof(h)/sizeof(human));
	// what the crap! don't do this, h[i].nBanana, XD
	/*for(int i=0;i++;i<sizeof(h)/sizeof(human))
	{
		std::cout << "-human " << i+1 << " : "
				<< "I took " << h[i].nBanana << " banana from my monkey friend"
				<< std::endl;
	}*/
	for(int i=0;i<sizeof(h)/sizeof(human);i++)
	{
		std::cout << "- " << i+1 << " th ";
		h[i].bananaGetting(monkeyKing);
	}
    return 0;
}
