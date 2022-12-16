#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using std::sort;
using std::vector;
using std::cout;
using std::string;
using std::ifstream;

namespace PartTwo{

	char getCommonItem(string &itemsFirstRucksack,string &itemsSecondRucksack,string &itemsThirdRucksack);
	int getSumOfPriorities(string pathToFile);
	int searchItem(string rucksack,char item);
	vector<vector<string>> getPuzzleInput(string pathToFile);
}
