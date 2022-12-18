/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
using std::sort;
using std::vector;
using std::cout;
using std::string;
using std::ifstream;

namespace PartOne{

	string getSubString(string word,int begin,int end);
	vector<vector<string>> getPuzzleInput(string pathToFile);
	char getCommonItem(string firstHalf,string secondHalf);
	int getSumOfPriorities(string pathToFile);
	int searchItem(string items,char item);
	int getPriorityOfChar(char item);
}
namespace PartTwo{

	char getCommonItem(string &itemsFirstRucksack,string &itemsSecondRucksack,string &itemsThirdRucksack);
	int getSumOfPriorities(string pathToFile);
	int searchItem(string rucksack,char item);
	vector<vector<string>> getPuzzleInput(string pathToFile);
}
