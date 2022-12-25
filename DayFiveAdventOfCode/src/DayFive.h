/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include<cstring>
#include<iostream>
#include<vector>
#include<fstream>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;

namespace PartOne{
	vector<vector<int>> getMovements(ifstream &puzzleInput);
	vector<vector<char>> getDistributionOfCrates(ifstream &puzzleInput);
	vector<char> topOfEveryStack(string pathToFile);
}
namespace PartTwo{

}
