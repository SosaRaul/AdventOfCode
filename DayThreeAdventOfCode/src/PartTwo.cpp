#include "PartTwo.h"


char PartTwo::getCommonItem(string &itemsFirstRucksack,string &itemsSecondRucksack,string &itemsThirdRucksack){
	// I need sort because I will use binary search
	sort(itemsFirstRucksack.begin(),itemsFirstRucksack.end());
	sort(itemsSecondRucksack.begin(),itemsSecondRucksack.end());
	sort(itemsThirdRucksack.begin(),itemsThirdRucksack.end());
	unsigned int i = 0;
	int resultSearchInSecond,resultSearchInThird;
	while(i < itemsFirstRucksack.length()){
		resultSearchInSecond = PartTwo::searchItem(itemsSecondRucksack,itemsFirstRucksack[i]);
		resultSearchInThird = PartTwo::searchItem(itemsThirdRucksack,itemsFirstRucksack[i]);
		if((itemsSecondRucksack[resultSearchInSecond] == itemsThirdRucksack[resultSearchInThird]) && resultSearchInSecond != -1 ){
			return itemsFirstRucksack[resultSearchInSecond];
		}
		i++;
	}
}
int PartTwo::getSumOfPriorities(string pathToFile){



}
int PartTwo::searchItem(string rucksack,char item){
	int lo = 0, hi = rucksack.length()-1;
	while(lo <= hi){
		int mid = lo+(hi-lo)/2;
		if(item < rucksack[mid]){
			hi = mid-1;
		}else if(item > rucksack[mid]){
			lo = mid+1;
		}else{
			return mid;
		}
	}
	return -1;
}

vector<vector<string>> PartTwo::getPuzzleInput(string pathToFile){

	ifstream puzzleInput(pathToFile);
	string lineFromFile;
	vector<string> items;
	vector<vector<string>> groups;
	int processedLines = 0;

	if(puzzleInput.is_open()){
		while(puzzleInput.eof() == false){
			getline(puzzleInput,lineFromFile);
			processedLines++;
			if(processedLines % 4 != 0){
				// Fill array of items , items inside rucksack
				items.push_back(lineFromFile);
			}else{
				groups.push_back(items);
				items.clear();
				items.push_back(lineFromFile);
			}
		}
	}else{
		cout << "Can't open the file provided.";
	}
	return groups;
}
