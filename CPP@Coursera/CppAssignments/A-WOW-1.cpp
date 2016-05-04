/*
 * C++ @ Coursera, assignment -> World of Warlords: preparation
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

// headquarters
struct HeadQuarter
{
	int nWarriors;
	std::vector<std::string> nameOrder;
	std::vector<int> strengthOrder;
	std::vector<int> nCreated;

};

/* class Warrior
{
private:
	int m_index;
	int m_strength;
	std::string m_name;
public:
	Warrior(int i, int s, std::string n): m_index(i), m_strength(s), m_name(n)
	{
		std::cout << m_name << " " << m_index << " born with strength "
				  <<
	}
}; */

// Input Cases
struct InputCase
{
	int IndCase;
	int TotalStrength;
	int StrengthTable[5];
};

int main()
{
	/*
	 * get cases from input
	 * assuming input ends with EOF or non-number characters (hope so! to be checked)
	 */

    std::vector<InputCase> Cases;
    InputCase temp;

    // Input line 1 must be effective / check for EOF
    while ( std::cin >> temp.IndCase && !std::cin.eof() )
    {

    	// Input line 2 must be effective
    	if(std::cin >> temp.TotalStrength)
    	{

    		// Input line 3 must be effective
    		bool StrengthTableGood = true;
			for(int i=0; i<5; i++)
			{
				if(std::cin >> temp.StrengthTable[i])
					std::cout << "exe" << std::endl;
				else
				{
					StrengthTableGood = false;
					break;
				}
			}

			// add to Input cases list if all lines are okay
			if(StrengthTableGood)
				Cases.push_back(temp);
    	}

    }


    /* initialize two headquarters, create name order and strength order */
    HeadQuarter red, blue;
    red.nWarriors = 0;
    blue.nWarriors = 0;
    red.nCreated = {0,0,0,0,0};
    blue.nCreated = {0,0,0,0,0};
    red.nameOrder = { "iceman", "lion", "wolf", "ninja", "dragon" };
    blue.nameOrder = { "lion", "dragon", "ninja", "iceman", "wolf" };
    std::map<std::string, int> name2Strength;
    std::string InputNameOrder[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
    for(int i=0; i<5; i++)
    	name2Strength.insert( std::pair<std::string, int> (InputNameOrder[i], Cases.at(0).StrengthTable[i]) );
    std::map<std::string, int>::iterator iter;
    for(int i=0; i<5; i++)
    {
    	iter = name2Strength.find(red.nameOrder.at(i));
    	red.strengthOrder.push_back(iter->second);
    	iter = name2Strength.find(blue.nameOrder.at(i));
    	blue.strengthOrder.push_back(iter->second);
    }


    /* for test */
    for(unsigned int i=0; i<red.strengthOrder.size(); i++)
    	std::cout << red.strengthOrder.at(i) << std::endl;
    for(unsigned int i=0; i<blue.strengthOrder.size(); i++)
    	std::cout << blue.strengthOrder.at(i) << std::endl;






    /*for (std::vector<InputCase>::iterator it_Cases=Cases.begin(); it_Cases != Cases.end(); it_Cases++ )
    {
    	std::cout << (*it_Cases).IndCase << std::endl;
    	std::cout << (*it_Cases).TotalStrength << std::endl;
    	for(int i=0; i<5; i++)
    		std::cout << (*it_Cases).StrengthTable[i] << std::endl;
    }*/

    std::cout << "end";
	return 0;
}
