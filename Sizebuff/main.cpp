//Reynald Walme - Program that uses both size of and buffer functions. 
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	const int BUFFER_SIZE = 100;	
	char mybuffer[BUFFER_SIZE];
	int a;
	char c;
	double d;
	float f;
	
	memset(mybuffer, 'A', sizeof(char) * BUFFER_SIZE);/*Sets the memory inside the buffer*/
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		cout<< mybuffer[i];
	}
	cout << endl;
	
	/*Shows the number of bytes each variable type uses.*/
	cout <<"Int has a byte size of: " << sizeof(a) << endl;
	cout << "Char has a byte size of: " << sizeof(c) << endl;
	cout << "Double has a byte size of: " << sizeof(d) << endl;
	cout << "Float has a byte size of: " << sizeof(f) << endl;
	cout << "Buffer has a byte size of: " << sizeof(mybuffer) << endl;
	
	
	system("PAUSE");
	return 0;
}