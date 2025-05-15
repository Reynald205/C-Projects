#include "DialogueTree.h"

DialogueNode::DialogueNode(string Text)
{
	text = Text;
}

DialogueOption::DialogueOption(string Text, int Returncode, DialogueNode *NextNode)
{
	text = Text;
	returncode = Returncode;
	nextnode = NextNode;
}

DialogueTree::DialogueTree()
{

}

void DialogueTree::init()
{
	DialogueNode *node0 = new DialogueNode("Hello Brave Warrior!");
	DialogueNode *node1 = new DialogueNode("I dont want to talk to you.");
	DialogueNode *node2 = new DialogueNode("I have a Quest for you!");
	DialogueNode *node3 = new DialogueNode("You will get 5 gold, You greedy swine.");
	DialogueNode *node4 = new DialogueNode("Collect 10 blades.");

	//Node 0
	node0->dialogueoptions.push_back(DialogueOption("Sup Noob!!!", 0, node1)); //(*node0).dialogueoptions.push_back can also be used.
	node0->dialogueoptions.push_back(DialogueOption("Hello Strange Voice!", 0, node2));
	dialoguenodes.push_back(node0);
	
	//Node1
	node1->dialogueoptions.push_back(DialogueOption("Awww!!!", 0, nullptr));
	dialoguenodes.push_back(node1);

	//Node2
	node2->dialogueoptions.push_back(DialogueOption("K Bye!", 0, nullptr));
	node2->dialogueoptions.push_back(DialogueOption("What is it?", 0, node4));
	node2->dialogueoptions.push_back(DialogueOption("What's the pay?", 0, node3));
	dialoguenodes.push_back(node2);

	//Node3
	node3->dialogueoptions.push_back(DialogueOption("Okay, What is it?", 0, node4));
	node3->dialogueoptions.push_back(DialogueOption("That sucks, I'm out!", 0, nullptr));
	dialoguenodes.push_back(node3);
	
	//Node4
	node4->dialogueoptions.push_back(DialogueOption("Let's do it!!!", 1, nullptr));
	node4->dialogueoptions.push_back(DialogueOption("No way!!!", 0, nullptr));
	dialoguenodes.push_back(node4);
}

void DialogueTree::destroyTree()
{
	for (int i = 0; i <dialoguenodes.size(); i++)
	{
		delete dialoguenodes[i];
	}
	dialoguenodes.clear();
}

int DialogueTree::performDialogue() 
{
	if (dialoguenodes.empty())
	{
		return -1;
	}
	DialogueNode *currentnode = dialoguenodes[0];
	
	while (true)
	{
		cout << currentnode->text << "\n\n";
		for (int i = 0; i < currentnode->dialogueoptions.size(); i++)
		{
			cout << i + 1 << ": " << currentnode->dialogueoptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;

		if (input < 0|| input > currentnode->dialogueoptions.size())
		{
			cout << "Invalid Input!\n" << endl;
		}
		else
		{
			//Check for the end of the conversation.
			if (currentnode->dialogueoptions[input].nextnode == nullptr)
			{
				return currentnode->dialogueoptions[input].returncode;
			}
			currentnode = currentnode->dialogueoptions[input].nextnode;
		}
		cout << endl;
	}
	return 0;
}
