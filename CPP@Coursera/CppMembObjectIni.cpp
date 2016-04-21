/*
 * Initialization of Member Objects in C++
 * when we initialize an object in a constructor, its member object should also be initialized by their own constructors
 * we can do this using initialization list,
 * e.g. Object1(type arg1, type arg2): object2(arg1), object3(arg1, arg2) {}
 *
 * bug comes if we use the default constructor of an object, of which the members have manual written constructors
 * in the previous projects like solar system wrote we kind of thing like Object1.ini(){ object2.ini(); object2.ini(); }
 */

#include <iostream>

class Ctyre
{
private:
	double radius;
	bool isRacing;
public:
	/*Ctyre(double r, bool race): radius(r),isRacing(race)
    {
		std::cout << "tyre cons with radius of" << radius << std::endl;
    }*/
	~Ctyre(){ std::cout << "tyre des" << std::endl; }
};


class Cengine
{
private:
	double power;
public:
	/*Cengine(double p): power(p) { std::cout << "engine cons" << std::endl; }*/
	~Cengine() { std::cout << "engine des" << std::endl; }
};

class Ccar
{
private:
	Ctyre tyre;
	Cengine engine;
public:
	//Ccar(double r, bool race, double p);
    ~Ccar() { std::cout << "sorry, your car is taken by the coops :D" << std::endl; }
};

/*Ccar::Ccar(double r, bool race, double p): tyre(r,race), engine(p)
{
	std::cout << "here is your car :)" << std::endl;
}*/

int main()
{
    Ccar car/*(100, false, 50)*/;
	return 0;
}

