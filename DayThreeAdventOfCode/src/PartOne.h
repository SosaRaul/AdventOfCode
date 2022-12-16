/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include<vector>
#include<iostream>
#include<fstream>
using std::string;
using std::vector;
using std::ifstream;
using std::cout;

namespace PartOne{

	string getSubString(string word,int begin,int end);
	vector<vector<string>> getPuzzleInput(string pathToFile);
	char getCommonItem(string firstHalf,string secondHalf);
	int getSumOfPriorities(string pathToFile);
	int searchItem(string items,char item);

}

namespace PartTwo{


}
