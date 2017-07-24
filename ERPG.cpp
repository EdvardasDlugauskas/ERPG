#include "stdafx.h"
#include "windows.h"
#include "fstream"
#include "stdio.h"
#include <iostream>
#include <string>
#include "GameSequence.h"

using namespace std;

void ShowMainMenu();
void NewGame();
void LoadGame();
void Options();
void About();
int Exit();

string gamever = "ERPG indev v0.01";
string gamebuild = "I0001";
string builddate = "2017-07-24";
bool isstable = false;
bool isbeta = true;
bool isdebug = true;

void WriteSaveFile(int lvl, int exp)
{
	ofstream savewrite("save.sav");
	savewrite << lvl;
	savewrite << " ";
	savewrite << exp;
	savewrite.close();
}

void CreateCharacter()
{
	system("cls");
	cout << "Select Character!" << endl;
	cout << "-------------------------" << endl;
	cout << "1) Mage" << endl;
	cout << "2) Pink Guy" << endl;
	cout << "3) Shaman" << endl;
	cout << "4) Budhist" << endl;
	cout << "-------------------------" << endl;
	int chrselection = 0;
	cin >> chrselection;
	string charactertemp;
	switch (chrselection)
	{
	case 1:
		charactertemp = "Mage";
		break;
	case 2:
		charactertemp = "Pink Guy";
		break;
	case 3:
		charactertemp = "Shaman";
		break;
	case 4:
		charactertemp = "Budhist";
		break;
	default:
		cout << "Wrong key entered, please try again!" << endl;
		Sleep(2000);
		system("cls");
		CreateCharacter();
	}
	cout << "Character " << charactertemp << " succesefully created!" << endl;
	ofstream writechr("chr.chr");
	writechr << charactertemp;
	writechr.close();
	WriteSaveFile(0, 0);
	gamesequenceactual();
}

void NewGame()
{
	CreateCharacter();
}

void LoadGame()
{

}

void Options()
{

}

void About()
{

}

int Exit()
{
	return 0;
}

void ShowMainMenu()
{
	system("cls");
	cout << gamever << endl;
	cout << "---------------------" << endl;
	cout << "1) New Game" << endl;
	cout << "2) Load Game" << endl;
	cout << "3) Options " << endl;
	cout << "4) About" << endl;
	cout << "5) Exit" << endl;
	cout << "---------------------" << endl;
	int menuselection = 0;
	cin >> menuselection;
	switch(menuselection)
	{
		case 1:
			NewGame();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			Options();
			break;
		case 4:
			About();
			break;
		case 5:
			Exit();
			break;
		default:
			cout << "Wrong key entered, try again!" << endl;
			Sleep(2000);
			system("cls");
			ShowMainMenu();
	}
}

int main()
{
	ShowMainMenu();
}

