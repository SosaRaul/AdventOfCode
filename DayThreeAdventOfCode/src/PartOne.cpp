/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "PartOne.h"

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
		commonItem = getCommonItem(rucksacks[i][0],rucksacks[i][1]);
		if(searchItem("abcdefghijklmnopqrstuvwxyz",commonItem) != -1){
			sum += commonItem - 96;
		}else if (searchItem("ABCDEFGHIJKLMNOPQRSTUVWXYZ",commonItem) != -1){
			sum += commonItem - 38;
		}
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
