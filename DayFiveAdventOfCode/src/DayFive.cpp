/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "DayFive.h"
string getNumberFromString(string str,int begin,int end);

string PartOne::getLineWithoutSpaces(string line){
    string phraseWithoutSpaces = "";
    for(unsigned int i = 0;i<line.length();i++){
        if(line[i] != ' '){
            phraseWithoutSpaces += line[i];
        }
    }
    return phraseWithoutSpaces;
}
vector<int> PartOne::movementsParser(string line){
	vector<int> cratesAndStacks;
	string lineWithoutSpaces = getLineWithoutSpaces(line);
	int firstPosition = lineWithoutSpaces.find("from",3);
	int secondPosition = lineWithoutSpaces.find("to",5);

	string quantityOfCrates = getNumberFromString(lineWithoutSpaces,4,firstPosition-1);
	string positionFirstStack = getNumberFromString(lineWithoutSpaces,firstPosition+4,secondPosition-1);
	string positionSecondStack = getNumberFromString(lineWithoutSpaces,secondPosition+2,lineWithoutSpaces.length()-1);

	cratesAndStacks.push_back(atoi(quantityOfCrates.c_str()));
	cratesAndStacks.push_back(atoi(positionFirstStack.c_str()));
	cratesAndStacks.push_back(atoi(positionSecondStack.c_str()));

	return cratesAndStacks;
}

string cstringToString(char str[]){
	string cplusplusString = "";
	for(unsigned int i = 0;i<strlen(str);i++){
		cplusplusString += str[i];
	}
	return cplusplusString;
}
string getNumberFromString(string str,int begin,int end){
	string number = "";
	for(unsigned int i = begin;i <= end;i++){
		number.push_back(str[i]);
	}
	return number;
}
