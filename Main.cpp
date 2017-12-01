#include <iostream> 
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cassert>

using namespace std;

const char BLANK = ' ';
const char LEAF = '#';
const char WOOD = '|';


int main()
{

	void produceChristmasGreeting();
	produceChristmasGreeting();

	bool agreeToContinue(bool &more);
	bool more = agreeToContinue(more);
	void drawAXmasTree();
	while (more == true)
	{
		drawAXmasTree();
		bool more = agreeToContinue(more);
		if (more == false){
			break;
		}
	}

	system("pause");
	return (0);

}

void produceChristmasGreeting()
{
	void drawAXmasTree();
	cout << "Claire Smith - 1T - Tuesday 13th December\n\n";
	drawAXmasTree();
} //end of produceChristmasGreeting

void drawAXmasTree()
{
	int height = 0;
	int branchLine = 0;
	int dots = 1;
	const char dot = '.';
	int getValidHeight(int &treeHeight);
	void drawBranches(int treeHeight, int &bLine);
	void drawTrunk(int treeHeight);

	getValidHeight(height);
	drawBranches(height, branchLine);
	drawTrunk(height);

	for (dots = 1; dots <= (height - 2) + ((height - 2) + 1); dots++)
	{
		cout << dot;
	}
	cout << "\n";
}// end of drawAXmasTree

int getValidHeight(int &treeHeight)
{
	cout << "Enter the size of the tree (4-20): ";
	cin >> treeHeight;

	while (treeHeight <= 3 || treeHeight >= 21)
	{
		cout << "ERROR: Invalid height! Enter the size of the tree (4-20): ";
		cin >> treeHeight;
	}
	return treeHeight;

}// end of getValidHeight

void drawBranches(int treeHeight, int &bLine)
{
	
	void drawABranch(int treenHeight, int bLine);
	char randomDecoration();
	const int leafHeight = treeHeight - 2; //made as a constant to simplify expressions later on
	int spaces = 1;
	const char dot = '.';
	int dots = 1;

	for (dots = 1; dots <= (leafHeight)+((leafHeight)+1); dots++)
	{
		cout << dot;
	}
	cout << "\n";
	bLine = 1;
	spaces = (leafHeight)-bLine;
	cout << dot;
	for (spaces = (leafHeight-bLine); spaces > 0; spaces--)
	{
		cout << BLANK;
	}//end of for loop

	cout << randomDecoration();
	spaces = 1;
	for (spaces = (leafHeight-bLine); spaces > 0; spaces--)
	{
		cout << BLANK;
	}//end of for loop
	cout << dot;
	cout << "\n";
	++bLine;


	do
	{
		drawABranch(treeHeight, bLine);
		++bLine;
	} while (bLine <= (leafHeight));//end of do...while loop
}//end of drawBranches

void drawABranch(int treeHeight, int bLine)
{
	int spaces, leafs;
	const int leafHeight = treeHeight - 2; //made constant as used a lot
	spaces = leafHeight-bLine;
	void setColour(int index);
	void resetColour();
	const char dot = '.';

	cout << dot;
	for (spaces = (leafHeight-bLine); spaces > 0; spaces--)
	{
		cout << BLANK;
	}//end of for loop

	leafs = 1;
	for (leafs = 1; leafs <= (bLine + (bLine - 1)); leafs++)
	{
		setColour(2);
		cout << LEAF;
	}//end of for loop
	resetColour();
	spaces = 1;
	for (spaces = (leafHeight-bLine); spaces > 0; spaces--)
	{
		cout << BLANK;
	}//end of for loop
	cout << dot;
	cout << "\n";
}// end of drawABranch

void drawTrunk(int treeHeight)
{
	int trunkLine, spaces;
	const char dot = '.';
	void setColour(int index);
	void resetColour();
	trunkLine = 1;

	while (trunkLine <= 2)
	{
		spaces = 1;
		cout << dot;
		while (spaces <= (treeHeight - 3))
		{
			cout << BLANK;
			++spaces;
		}//end of while loop
		setColour(4);
		cout << WOOD;
		resetColour();
		spaces = 1;
		while (spaces <= (treeHeight - 3))
		{
			cout << BLANK;
			++spaces;
		}//end of while loop
		cout << dot;
		cout << "\n";
		++trunkLine;
	}//end of while loop
}//end of drawTrunk

bool agreeToContinue(bool &more)
{
	char answer;
	cout << "Would you like another tree? (Y/N) :";
	cin >> answer;

	if (answer == 'y' || answer == 'Y')
	{
		more = true;
	}
	else
	{
		more = false;
	}

	return more;
} //end of agreeToContinue

char randomDecoration()
{
	srand(time(0));
	int num = (rand() % 4 + 1); //chooses a random number between 1 and 4
	char d;
	switch (num)
	{
	case 1: d = '*'; break;
	case 2: d = '&'; break;
	case 3: d = '@'; break;
	default: d = '0';
	}
	return d;
}

/* http://www.cplusplus.com/forum/windows/45270/ */
void setColour(int index)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index); //allows colour to be selected when function is called
}//end of setColour



void resetColour()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//changes back to original colour text
}//end of resetColour
