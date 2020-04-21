#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string data;
	vector<int> count;
	vector<int> numFace;

	ifstream inFile;
	inFile.open("dice.txt");

	while (!inFile.eof())
	{
		//parsing numbers from strings into 2 vectors
		inFile >> data;
		int dPos = data.find_first_of('d');
		count.push_back(stoi(data.substr(0, dPos)));
		numFace.push_back(stoi(data.substr(dPos + 1, data.length())));
	}
	inFile.close();

	//Outputting
	ofstream outFile("sum.txt");
	int bound = count.size();
	for (int i = 0; i < bound; i++)
	{
		int sum = 0;
		int time = count[i];
		int faceType = numFace[i];
		while (time > 0)
		{
			int randNum = rand() % faceType + 1;
			sum += randNum;
			time--;
		}

		//Converting into string and outputting
		string sumStr;
		sumStr += to_string(sum) + "\n";

		outFile << sumStr;
	}
	outFile.close();
}
