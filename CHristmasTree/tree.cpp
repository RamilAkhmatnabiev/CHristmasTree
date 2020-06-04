#include "tree.h"
using namespace std;

Tree::Tree(int height)
{
	a = 0;
	lightMode = 0;
	this->height = height;
	this->tree = new PartOfTree * [height];

	for (size_t i = 0; i < height; i++)
	{
		this->tree[i] = new PartOfTree[i + 1];
	}
	Build();
}

Tree::~Tree()
{
	for (int i = 0; i < height; i++)
	{
		delete[] tree[i];
	}
	delete tree;
}

void Tree::TurOn()
{
	this->isOn = true;
	thread key_thread([&]() {KeyboardPars(); });


	while (isOn)
	{
		//thread key_thread([&]() {KeyboardPars(); });
		RefreshTree();
		
		

		if (this->PressedKey > -1)
		{
			system("cls");
			cout << "key pressed. Light mode changed" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
			lightMode++;
			lightMode %= 2;
			PressedKey = -1;
		}
		system("cls");

		//key_thread.detach();
	}
	key_thread.detach();
}

void Tree::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				//for (int k = 0; k < (height / (i + 2)) / 2; k++)
				for (int k = 0; k < (height - i + 5) / 1.7; k++)
				{
					cout << ' ';
				}
			}

			//cout << tree[i][j].value;
			tree[i][j].Print();
		}
		cout << endl;
	}
}

void Tree::Build()
{
	int tempCount = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (tree[i][j].isLightBuld)
			{
				tree[i][j].value = tempCount;
				++tempCount;
				if (tempCount >= 10)
				{
					tempCount = 0;
				}
			}
			else
			{
				tree[i][j].value = 0;
			}

		}
	}
}

void Tree::RefreshTree()
{
	switch (lightMode)
	{
		case 0:
		for (int i = 0; i < height; i++)
		{
			for (size_t j = 0; j < i + 1; j++)
			{
				if (tree[i][j].isLightBuld)
				{
					tree[i][j].value++;
					if (tree[i][j].value >= 9)
					{
						tree[i][j].value = tree[i][j].value % 10;
					}
				}
			}
		}
		Print();
		this_thread::sleep_for(chrono::milliseconds(500));
		break;

		case 1:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < i + 1; j++)
				{
					if (tree[i][j].isLightBuld)
					{
						tree[i][j].value++;
						if (tree[i][j].value >= 9)
						{
							tree[i][j].value = tree[i][j].value % 10;
						}
						Print();
						this_thread::sleep_for(chrono::milliseconds(50));
						system("cls");
					}
				}
			}
			break;
	default:
		break;
	}
	
}

void Tree::KeyboardPars()
{
	while (isOn)
	{
		this->PressedKey = _getch();
	}
}
