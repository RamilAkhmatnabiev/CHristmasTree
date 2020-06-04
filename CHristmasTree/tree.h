#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class PartOfTree; // prototype



class Tree
{
	class PartOfTree;// иначе не работает двумерный динамический массив из PartOfTree
public:
	
	static int a;
	Tree(int height);
	~Tree();
	void TurOn();

	
private:
	PartOfTree** tree;
	//int** tree;
	int height;
	bool isOn = false;
	int PressedKey = -1;
	int lightMode;
	void Print();
	void Build();
	void RefreshTree();
	void KeyboardPars();
	class PartOfTree
	{
	public:
		int value;
		bool isLightBuld;
		PartOfTree()
		{
			value = 0;
			isLightBuld = a % 2;
			a++;
		}

		void Print()
		{
			/*int colorNumber = rand() % 8;
			char symbol = colorNumber + '0';
			char* cmd = new char[8]{ 'c','o','l','o','r',' ',symbol,'\n'}; 
			system(cmd);*/
			cout << value;
		}
		
	};
};


