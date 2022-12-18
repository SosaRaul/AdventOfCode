/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "DayFour.h"

bool PartOne::isIncludedInSet(unsigned int a,unsigned int b,unsigned int c,unsigned int d){
	return a>=c && a<=b && b<=d && b>=a;
}
int PartOne::countPairsIncludedInOthers(string pathToFile){
	ifstream puzzleInput(pathToFile);
	string lineFromFile;
	int count = 0;

	if(puzzleInput.is_open()){
		while(!puzzleInput.eof()){
			getline(puzzleInput,lineFromFile);
			vector<int> extremes = getExtremesFromIntervals(lineFromFile);
			if(isIncludedInSet(extremes[0],extremes[1],extremes[2],extremes[3]) || isIncludedInSet(extremes[2],extremes[3],extremes[0],extremes[1])){
				count++;
			}
		}
	}else{
		cout << "Can't open file provided!";
	}
	return count;
}

vector<int> PartOne::getExtremesFromIntervals(string line){
	string acumulator = "";
	vector<int> listOfExtremes;

	for(unsigned int i = 0;i < line.length();i++){
		if(line[i] != '-' && line[i] != ','){
			acumulator += line[i];
		}else{
			listOfExtremes.push_back(atoi(acumulator.c_str()));
			acumulator = "";
		}
	}
	listOfExtremes.push_back(atoi(acumulator.c_str()));
	return listOfExtremes;
}
