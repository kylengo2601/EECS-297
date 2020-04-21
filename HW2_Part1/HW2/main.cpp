#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string dataIn;
	vector<string> lSideArr;  //times to run rand()
	vector<string> rSideArr; //rSideArr and possible multiply with const 

	ifstream inFile;
	inFile.open("dice_part_1.txt");

	while (!inFile.eof())
	{
		//parsing strings on 2 sides of 'd' into 2 vectors
		inFile >> dataIn;
		int dPos = dataIn.find_first_of('d');
		lSideArr.push_back(dataIn.substr(0, dPos));
		rSideArr.push_back(dataIn.substr(dPos + 1, dataIn.length()));
	}

	//check for abnomalies in left and right sides of 'd'
	//then calculate the two sides
	//then calculate sums
	//then put the sums in a string
	string dataOut;
	int bound = lSideArr.size();
	for (int i = 0; i < bound; i++) 
	{
		int constant = 1;
		int time;
		int range;
		int sum = 0;

		//checking left side of 'd'
		if (lSideArr[i].find_first_of('*') == -1) {  //if just a number
			time = stoi(lSideArr[i]);
		}
		else {                             
			int xPos = lSideArr[i].find_first_of('*');
			constant = stoi(lSideArr[i].substr(0, xPos));
			time = stoi(lSideArr[i].substr(xPos + 1, lSideArr[i].length()));
		}
		
		//checking right side of 'd'
		if (rSideArr[i].find_first_of('+') == -1 || rSideArr[i].find_first_of('-') == -1) {
			range = stoi(rSideArr[i]);
		} else {
			if (rSideArr[i].find_first_of('+') == -1) {    //if its '-' sign
				int signPos = lSideArr[i].find_first_of('-');
				int firstNum = stoi(rSideArr[i].substr(0, signPos));
				int secondNum = stoi(rSideArr[i].substr(signPos + 1, rSideArr[i].length()));
				range = firstNum - secondNum;
			} else {
				int signPos = lSideArr[i].find_first_of('+');
				int firstNum = stoi(rSideArr[i].substr(0, signPos));
				int secondNum = stoi(rSideArr[i].substr(signPos + 1, rSideArr[i].length()));
				range = firstNum + secondNum;
			}
		}
		
		//calculating sums
		while (time > 0) 
		{
			int randNum = rand() % range + 1;
			sum += constant * randNum;
			time--;
		}

		//putting sum into a string
		dataOut += to_string(sum) + "\n";

	}
	inFile.close();

	//Outputting
	ofstream outFile("sum.txt");
	outFile << dataOut;
	outFile.close();
}
