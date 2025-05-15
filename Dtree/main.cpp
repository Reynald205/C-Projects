//Reynald Walme - Program that creates a Dialogue Tree.
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "DialogueTree.h"
using namespace std;

int main() {
	DialogueTree dialogue;
	dialogue.init();
	int rv = dialogue.performDialogue();
	if (rv == 1)
	{
		cout << "\nYou Accepted the Quest!\n" ;
	}

	dialogue.destroyTree();
	cout << "Enter any key to continue...\n" << endl;
	int tmp;
	cin >> tmp;

	return 0;
}