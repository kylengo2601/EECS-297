#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main() {
	string dataIn;
	string inputString;
	
	ifstream fileIn;
	fileIn.open("dice_part_2.txt");

	//inputting file into a string
	while (!fileIn.eof()) 
	{
		//to get exact same contents as txt file
		getline(fileIn, dataIn);
		inputString += dataIn + "\n";
		
	}

	ofstream fileOut("sum.txt");
	//outFile << dataOut;
	
	//Preparing for output	
	for (int i = 0; i < inputString.length(); i++) //going thru every character till find 'd' with numbers on both sides
	{
		int lEnd = i;
		int rEnd = i;
		//find 'd' having numbers on both sides
		//then take a substring
		if (inputString[i] == 'd') {
			//checking for numbers on the sides of 'd'
			int rSide = i - 1;
			int lSide = i + 1;
			if (isdigit(inputString[rSide]) && isdigit(inputString[lSide])) {
				bool foundLeftEnd = false;
				bool foundRightEnd = false;
				while (!foundLeftEnd)
				{
					lEnd -= 1;
					if (inputString[lEnd] == ' ') {
						foundLeftEnd = true;
					}
				}
				while (!foundRightEnd)
				{
					rEnd += 1;
					if (inputString[rEnd] == ' ') {
						foundRightEnd = true;
					}
				}
				//NOTE: substring takes first element and does not take last element
				lEnd += 1;
				int strSize = rEnd - lEnd;
				string dice = inputString.substr(lEnd, strSize);
				size_t dPos = dice.find_first_of('d');
				
				//getting the 2 numbers
				int faceNum = stoi(dice.substr((_int64)dPos + 1, strSize - (_int64)dPos));
				int timeRoll = stoi(dice.substr(0, dPos));
				
				//calculating sums
				int sum = 0;
				int randNum = rand() % faceNum + 1;
				while (timeRoll > 0)
				{
					sum += randNum;
					timeRoll -= 1;
				}

				//putting sum back into string
				inputString.replace(lEnd, rEnd+1, dice, to_string(sum));
				/*string dataOut;
				dataOut += to_string(sum) + "\n";
				fileOut << dataOut;*/
			}
		}
	}
	fileIn.close();
	fileOut.close();
}