/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "DayFive.h"
using std::cout;
int main(){


	string line = "move 6 from 1 to 7";
	vector<int> result = PartOne::movementsParser(line);
	for(unsigned int i = 0;i<result.size();i++){
		cout << result[i] << " ";
	}

	return 0;
}

