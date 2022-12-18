/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "DayThree.h"

// Precondition : path to input must be valid
vector<vector<string>> PartOne::getPuzzleInput(string pathToFile){

	ifstream puzzleInput(pathToFile);
	string lineFromFile;
	vector<vector<string>> rucksacks;
	vector<string> items;

	if(puzzleInput.is_open()){
		while(!puzzleInput.eof()){
			// Read one line.
			getline(puzzleInput,lineFromFile);
			// Save first half
			items.push_back(getSubString(lineFromFile,0,lineFromFile.length()/2-1));
			// Save second half.
			items.push_back(getSubString(lineFromFile,lineFromFile.length()/2,lineFromFile.length()-1));
			// Save rucksack
			rucksacks.push_back(items);
			items.clear();
		}
	}else{
		cout << "Can't open the file provided.";
	}
	return rucksacks;

}
// Precondition : @word is a string c++ type, @begin and @end are valid index in word.
string PartOne::getSubString(string word,int begin,int end){
	string subString;
	for(int i = begin;i <= end;i++){
		subString += word[i];
	}
	return subString;
}
// Preconditon : Only one & unique common item!
char PartOne::getCommonItem(string firstHalf,string secondHalf){
	// Find common item using binary search
	for(unsigned int i = 0;i < secondHalf.length();i++){
		if(searchItem(firstHalf,secondHalf[i]) != -1){
			return secondHalf[i];
		}
	}
}
// PART ONE!!
int PartOne::getSumOfPriorities(string pathToFile){
	int sum = 0;
	char commonItem;
	vector<vector<string>> rucksacks = getPuzzleInput(pathToFile);
	for(unsigned int i = 0;i < rucksacks.size();i++){
		sum += getPriorityOfChar(getCommonItem(rucksacks[i][0],rucksacks[i][1]));
	}
	return sum;
}

int PartOne::searchItem(string items,char item){
	unsigned int i = 0;
	while(i < items.length() && items[i] != item){
		i++;
	}
	return i == items.length() ? -1 : i;
}

int PartOne::getPriorityOfChar(char item){
	int priority;

	if(PartOne::searchItem("abcdefghijklmnopqrstuvwxyz",item) != -1){
		priority = item - 96;
	}else if(PartOne::searchItem("ABCDEFGHIJKLMNOPQRSTUVWXYZ",item) != -1){
		priority = item - 38;
	}
	return priority;
}

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
		if((itemsSecondRucksack[resultSearchInSecond] == itemsThirdRucksack[resultSearchInThird]) && resultSearchInSecond != -1 && resultSearchInThird != -1){
			return itemsSecondRucksack[resultSearchInSecond];
		}
		i++;
	}
}
int PartTwo::getSumOfPriorities(string pathToFile){

	vector<vector<string>> groups = PartTwo::getPuzzleInput(pathToFile);
	int sum = 0;

	for(unsigned int i = 0;i < groups.size();i++){
		sum += PartOne::getPriorityOfChar(PartTwo::getCommonItem(groups[i][0],groups[i][1],groups[i][2]));
	}
	return sum;
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
	int processedLines = -1;

	if(puzzleInput.is_open()){
		while(puzzleInput.eof() == false){
			for(unsigned int i = 0;i < 3;i++){
				getline(puzzleInput,lineFromFile);
				items.push_back(lineFromFile);
			}
			groups.push_back(items);
			items.clear();
		}
	}else{
		cout << "Can't open the file provided.";
	}
	return groups;
}
