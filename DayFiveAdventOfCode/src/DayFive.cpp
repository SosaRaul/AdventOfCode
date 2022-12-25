/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "DayFive.h"
string getNumberFromString(string str,int begin,int end);
string getLineWithoutSpaces(string line);

vector<char> topOfEveryStack(string pathToFile){
	// 1 - leer el estado original de las pilas y los movimientos a realizar.
	// 2 - Aplicar lo leido en 1.
	// 3 - Obtener para cada pila quien esta en su cima.
}




vector<vector<char>> PartOne::getDistributionOfCrates(string pathToFile){
	int j = 0;
	ifstream puzzleInput(pathToFile);

	vector<vector<char>> matrixOfCrates;
	int lineCounter = 0;
	string line;

	if(puzzleInput.is_open()){
		while(lineCounter < 10){
			getline(puzzleInput,line);
			vector<char> currentRow(9,' ');
			for(unsigned int i = 1;i <line.length();i+=4){
		            currentRow[j] = line[i];
		            j++;
			}
			matrixOfCrates.push_back(currentRow);
			lineCounter++;
			j = 0;
		}
	}else{
		cout << "Can't open file provided! ";
	}
	return matrixOfCrates;
}

// Retorna vector de int con los movimientos para hacer segun cada fila del archivo
//vector<vector<int>> PartOne::getMovements(string line){
//	vector<int> cratesAndStacks;
//	string lineWithoutSpaces = getLineWithoutSpaces(line);
//	int firstPosition = lineWithoutSpaces.find("from",3);
//	int secondPosition = lineWithoutSpaces.find("to",5);
//
//	string quantityOfCrates = getNumberFromString(lineWithoutSpaces,4,firstPosition-1);
//	string positionFirstStack = getNumberFromString(lineWithoutSpaces,firstPosition+4,secondPosition-1);
//	string positionSecondStack = getNumberFromString(lineWithoutSpaces,secondPosition+2,lineWithoutSpaces.length()-1);
//
//	cratesAndStacks.push_back(atoi(quantityOfCrates.c_str()));
//	cratesAndStacks.push_back(atoi(positionFirstStack.c_str()));
//	cratesAndStacks.push_back(atoi(positionSecondStack.c_str()));
//
//	return cratesAndStacks;
//}
string getNumberFromString(string str,int begin,int end){
	string number = "";
	for(unsigned int i = begin;i <= end;i++){
		number.push_back(str[i]);
	}
	return number;
}
string getLineWithoutSpaces(string line){
    string phraseWithoutSpaces = "";
    for(unsigned int i = 0;i<line.length();i++){
        if(line[i] != ' '){
            phraseWithoutSpaces += line[i];
        }
    }
    return phraseWithoutSpaces;
}
