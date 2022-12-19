/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 *
 */
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
namespace PartOne{

	/*
	 * Precondition: @a,@b,@c and @d are extremes from [a,b] and [c,d].
	 * [a,b] is where we're searching if [c,d] is inside
	 * Both intervals must be have only natural numbers.
	 *
	 * Post condition: Return true if [a,b] are inside of [c,d], otherwise return false.
	 */
	bool isIncludedInSet(unsigned int a,unsigned int b,unsigned int c,unsigned int d);
	/*
	 * Precondition: @pathToFile have format a,b-c,d for every line from file
	 * and a,b,c,d are natural numbers.
	 *
	 * Postcondition: Return array of int with a,b,c,d values
	 */
	vector<int> getExtremesFromIntervals(string line);


	/*
	 * Precondition: @pathToFile have format a,b-c,d for every line from file
	 * and a,b,c,d are natural numbers.
	 *
	 * Postcondition : Returns quantity of pairs included in others pairs
	 */
	int countPairsIncludedInOthers(string pathToFile);

}

namespace PartTwo{

	/*
	 * Precondition: @pathToFile have format a,b-c,d for every line from file
	 * and a,b,c,d are natural numbers.
	 *
	 * Postcondition: Returns quantity of overlapped pairs.
	 */
	int countOverlaps(string pathToFile);

	/* Precondition: @a,@b,@c and @d are extremes from [a,b] and [c,d].
	 * [a,b] is where we're searching if [c,d] is overlapped
	 * Both intervals must be have only natural numbers.
	 *
	 * Postcondition: Returns true if [c,d] overlaps on [a,b]
	 */
	bool areOverlaped(unsigned int a,unsigned int b,unsigned int c,unsigned int d);
}
