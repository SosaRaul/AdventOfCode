/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 */
#include "PartOne.h"
#include "PartTwo.h"

int main(){
	string var1 = "aadka";
	string var2 = "bccd";
	string var3 = "kkkkwd";
	cout << "Output Part One! : " << PartOne::getSumOfPriorities("src/input3") << "\n";
	cout << PartTwo::getCommonItem(var1,var2,var3);
	return 0;
}


