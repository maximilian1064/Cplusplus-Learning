/*
 * C++ @ Coursera, assignment -> World of Warlords: preparation
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

// headquarters
struct HeadQuarter
{
	int nWarriors;
	int strengthPoint;
	std::vector<std::string> nameOrder;
	std::vector<int> strengthOrder;
	std::vector<int> nCreated;

};


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

    // Input line of case number must be effective / check for EOF
    if( std::cin >> temp.IndCase && !std::cin.eof() )
    {

    	// Input line 1 must be effective / check for EOF

		while ( std::cin >> temp.TotalStrength && !std::cin.eof() )
		{
			// Input line 2 must be effective
			bool StrengthTableGood = true;
			for(int i=0; i<5; i++)
			{
				if( !(std::cin >> temp.StrengthTable[i]) )
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



    /*
     * show information for each case
     */

    for(unsigned int i_ca=0; i_ca<Cases.size(); i_ca++)
    {
    	/* Case index */
        std::cout << "Case:" << i_ca+1 << std::endl;

		/* initialize two headquarters, create name order and strength order */
		HeadQuarter red, blue;
		red.nWarriors = 0;
		blue.nWarriors = 0;

		red.nCreated = std::vector<int>(5,0);
		blue.nCreated = std::vector<int>(5,0);
		std::string temp1[5] = { "iceman", "lion", "wolf", "ninja", "dragon" };
		std::string temp2[5] = { "lion", "dragon", "ninja", "iceman", "wolf" };
		red.nameOrder.assign(temp1,temp1+5);
		blue.nameOrder.assign(temp2,temp2+5);

		std::map<std::string, int> name2Strength;
		std::string InputNameOrder[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
		for(int i=0; i<5; i++)
			name2Strength.insert( std::pair<std::string, int> (InputNameOrder[i], Cases.at(i_ca).StrengthTable[i]) );
		std::map<std::string, int>::iterator iter;
		for(int i=0; i<5; i++)
		{
			iter = name2Strength.find(red.nameOrder.at(i));
			red.strengthOrder.push_back(iter->second);
			iter = name2Strength.find(blue.nameOrder.at(i));
			blue.strengthOrder.push_back(iter->second);
		}
		red.strengthPoint = Cases.at(i_ca).TotalStrength;
		blue.strengthPoint = red.strengthPoint;


		/* show information */
		bool redRunout = false;
		bool blueRunout = false;
		int time = 0;
		int RedWarriorGenStartInd = 0;
		int BlueWarriorGenStartInd = 0;


		while( !(redRunout && blueRunout) )
		{

			/*show red headquarter information*/

			if(!redRunout)
			{
				redRunout = true;

				// creating a warrior in red headquarter
				for(int i=RedWarriorGenStartInd; i<RedWarriorGenStartInd+5; i++)
				{
					if( red.strengthPoint >= red.strengthOrder.at(i%5) )
					{
						red.nCreated.at(i%5) ++;
						std::cout << std::setw(3) << std::setfill('0') << time
								  << " red" << " " << red.nameOrder.at(i%5) << " " << time+1
								  << " born with strength" << " " << red.strengthOrder.at(i%5)
								  << "," << red.nCreated.at(i%5)
								  << " " << red.nameOrder.at(i%5)
								  << " in red headquarter"
								  << std::endl;
						red.strengthPoint -= red.strengthOrder.at(i%5);
						RedWarriorGenStartInd = i%5 + 1;
						redRunout = false;
						break;
					}
				}

				// stop making warriors when strength point runs out
				if(redRunout)
					std::cout << std::setw(3) << std::setfill('0') << time
							  << " red headquarter stops making warriors"
							  << std::endl;
			}


			/*show blue headquarter information*/

			if(!blueRunout)
			{
				blueRunout = true;

				// creating a warrior in blue headquarter
				for(int i=BlueWarriorGenStartInd; i<BlueWarriorGenStartInd+5; i++)
				{
					if( blue.strengthPoint >= blue.strengthOrder.at(i%5) )
					{
						blue.nCreated.at(i%5) ++;
						std::cout << std::setw(3) << std::setfill('0') << time
								  << " blue" << " " << blue.nameOrder.at(i%5) << " " << time+1
								  << " born with strength" << " " << blue.strengthOrder.at(i%5)
								  << "," << blue.nCreated.at(i%5)
								  << " " << blue.nameOrder.at(i%5)
								  << " in blue headquarter"
								  << std::endl;
						blue.strengthPoint -= blue.strengthOrder.at(i%5);
						BlueWarriorGenStartInd = i%5 + 1;
						blueRunout = false;
						break;
					}
				}

				// stop making warriors when strength point runs out
				if(blueRunout)
					std::cout << std::setw(3) << std::setfill('0') << time
							  << " blue headquarter stops making warriors"
							  << std::endl;
			}

			// time increment
			time++;

		}

    }


	return 0;
}
