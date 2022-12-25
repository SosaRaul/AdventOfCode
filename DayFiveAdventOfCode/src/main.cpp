/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "DayFive.h"
using std::cout;
int main(){

	ifstream puzzleInput("src/input5");
	PartOne::getDistributionOfCrates(puzzleInput);
	vector<vector<int>> matrix = PartOne::getMovements(puzzleInput);

	int lengthRows = matrix[0].size();
	int lengthColumns = matrix.size();
	for(unsigned int i=0;i<lengthColumns;i++){
		for(unsigned int j = 0;j<lengthRows;j++){
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

