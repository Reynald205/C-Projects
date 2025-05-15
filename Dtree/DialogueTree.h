#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DialogueNode; //Forward declaration.

class DialogueOption
{
public:
	DialogueOption(string Text, int Returncode,DialogueNode *NextNode);
	int returncode;
	string text;
	DialogueNode *nextnode;
};

class DialogueNode
{
public:
	DialogueNode(string Text);
	string text;
	vector <DialogueOption> dialogueoptions;
};

class DialogueTree
{
public:
	DialogueTree();
	void init();
	void destroyTree();

	int performDialogue();

private:
	vector <DialogueNode *> dialoguenodes;
};

