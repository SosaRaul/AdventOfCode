/*
 * Author : RaulSosa
 *
 * Dada una lista de lista de numeros (una matriz) . Calcular la suma de cada una de sus listas
 * internas y luego encontrar el top 3 de las listas cuyas sumas son las mas grandes.
 *
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int sumOfList(vector<int> list);
vector<vector<int>> getPuzzleInput(string pathToFile);
vector<int> getListOfSums(vector<vector<int>> list);
void showContentInPuzzleInput(vector<vector<int>> puzzleInput);
int dayOnePartOne(vector<vector<int>> list);
vector<int> dayOnePartTwo(vector<int> listOfSums);

int main(){


	cout << "\nMax sum : " << dayOnePartOne(getPuzzleInput("src/input.txt"));
	int first = dayOnePartTwo(getListOfSums(getPuzzleInput("src/input.txt")))[0];
	int second = dayOnePartTwo(getListOfSums(getPuzzleInput("src/input.txt")))[1];
	int thrid = dayOnePartTwo(getListOfSums(getPuzzleInput("src/input.txt")))[2];
	cout << "\nFirst : " << first << "\nSecond : " << second << "\nThrid : " << thrid;
	cout << "\nFist + Second + Thrird = " <<  first + second + thrid;
	return 0;
}

int dayOnePartOne(vector<vector<int>> list){
	return getListOfSums(list)[getListOfSums(list).size()-1];
}

// Return list with podium of max sums
vector<int> dayOnePartTwo(vector<int> listOfSums){
	vector<int> podiumPlusSum;
	podiumPlusSum.push_back(listOfSums[listOfSums.size()-1]);
	podiumPlusSum.push_back(listOfSums[listOfSums.size()-2]);
	podiumPlusSum.push_back(listOfSums[listOfSums.size()-3]);
	return podiumPlusSum;
}
vector<int> getListOfSums(vector<vector<int>> list){
	vector <int> listOfSums;
	// 1 step : generate list with all sums from every list in @list
	for(unsigned int i = 0;i < list.size();i++){
		listOfSums.push_back(sumOfList(list[i]));
	}
	// 2 step : sort the generated list.
	sort(listOfSums.begin(),listOfSums.end());
	return listOfSums;
}

int sumOfList(vector<int> list){
	int sum = 0;
	for(unsigned int i = 0;i < list.size();i++){
		sum += list[i];
	}
	return sum;
}
vector<vector<int>> getPuzzleInput(string pathToFile){

	ifstream puzzleInput(pathToFile);
	string value;
	vector<vector<int>> listOfLists;
	vector<int> listOfNumbers;

	if(puzzleInput.is_open()){
		// Iterate over each line from file
		while(!puzzleInput.eof()){
			// Read one line
			getline(puzzleInput,value);
			// If there's empty line then is the end of array internal
			if(value.length() == 0){
				// Append to external list.
				listOfLists.push_back(listOfNumbers);
				// Cleans list internal to save new values for next lines until empty line.
				listOfNumbers.clear();
			}else{
				listOfNumbers.push_back(stoi(value));
			}
		}
	}else{
		cout << "Can't open the file provided.";
	}
	return listOfLists;
}
void showContentInPuzzleInput(vector<vector<int>> puzzleInput){
	for(unsigned int i = 0;i < puzzleInput.size();i++){
		cout << "[" ;
		for(unsigned int j = 0;j < puzzleInput[i].size();j++){
			cout << puzzleInput[i][j] << " ";
		}
		cout << "]";
	}
}
