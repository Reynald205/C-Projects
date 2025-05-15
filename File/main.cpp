//Reynald Walme - Program that reads and write file data.
#include <iostream>
#include<string>
#include<cstdlib>
#include<fstream> //File stream much like cin and cout only for file reading and writing
#include <cstdio> //Needed to use printf

using namespace std;

int main() {
	int a = 5000;
	float b = 0.54574754f;
	ofstream outputFile;//Output to a file - writes the file.
	ifstream inputFile;//Input from a file -reads the file.
	
	/*outputFile.open("File.txt");  //to open a file, if file doesn't exist it will be created automatically. 
	if (outputFile.fail())
	{
		perror("File.txt");
		return 1;
	}
	outputFile << "Hello World!!!" << endl;
	outputFile.close();//Manually closes the output file.
	*/

	inputFile.open("File.txt");  //Reads the file. 
	if (inputFile.fail())
	{
		perror("File.txt");
		return 1;
	}
	string input;
	/*inputFile >> input; //This only gets one word */
	getline(inputFile, input);//Gets the whole line including whitespace.
	cout << input << endl;
	cout << "\n======================================\n" << endl;
	cout << "Hello World " << a <<" & "<< b << endl;

	cout << "\n======================================\n" << endl;
	printf("Hello World: %d %.2f \n", a, b); //Prints out an int(%d) and float(%f) for the printf function. Useful for formatting.
	//Can type indifferent commands in between the % and the type (d,f,etc.)

	system("PAUSE");
	return 0;
}