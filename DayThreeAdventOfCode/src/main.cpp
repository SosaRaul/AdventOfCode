/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */

/*
 * Para leer la entrada la estrategia es que a cada mochila la carguemos en un array desde el elemento 0 hasta el n/2 y desde
 * el n/2 + 1 al n en otro array.A su vez estos dos array son el elemento de un array donde cada posicion corresponde a una mochila.
 * Pasos : 1 Encontrar el elemento en comun de cada mitad del array.
 * Pasos : 2 Guardar la prioridad de ese  elemento en un acumulador.
 * Pasos : 3 retornar ese acumulador.
 *
 * Nota : la prioridad la consigo matcheando letra y valor según cuenta el enunciado.
 */


#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
string getSubString(string word,int begin,int end);
vector<vector<string>> getPuzzleInput(string pathToFile);
char getCommonItem(string firstHalf,string secondHalf);
int getSumOfPriorities(string pathToFile);
int searchItem(string items,char item);
int main(){

	//cout << getPuzzleInput("src/input3")[0][0]<<endl;
	//cout << getPuzzleInput("src/input3")[0][1];
	cout << getCommonItem("rzul","ladfdfdfdfz");

	return 0;
}
// Precondition : path to input valid
vector<vector<string>> getPuzzleInput(string pathToFile){

	ifstream puzzleInput("src/input3");
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
string getSubString(string word,int begin,int end){
	string subString;
	for(int i = begin;i <= end;i++){
		subString += word[i];
	}
	return subString;
}
// Preconditon : Only one character in common!
char getCommonItem(string firstHalf,string secondHalf){
	// Find common item using binary search.
	for(int i = 0;secondHalf.length();i++){
		if(searchItem(firstHalf,secondHalf[i]) != -1){
			return secondHalf[i];
		}
	}
}

int getSumOfPriorities(string pathToFile){

}

int searchItem(string items,char item){
	int lo = 0, hi = items.length()-1;
	while(lo <= hi){
		int mid = lo+(hi-lo)/2;
		if(item < items[mid]){
			hi = mid-1;
		}else if(item > items[mid]){
			lo = mid+1;
		}else{
			return mid;
		}
	}
	return -1;
}
