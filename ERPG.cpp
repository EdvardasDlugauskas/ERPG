#include "stdafx.h"
#include "windows.h"
#include "fstream"
#include "stdio.h"
#include <iostream>
#include <string>

using namespace std;


string gamever = "ERPG indev v0.03";
string gamebuild = "I0007";
string builddate = "2017-07-25 13:32";
bool isstable = false;
bool isbeta = true;
bool isdebug = true;

class Player
{
public:
	void PlayerStats()
	{

	}
private:
	void Debug()
	{

	}
};

class Game
{

public:


	void WriteSaveFile(int lvl, int exp)
	{
		ofstream savewrite("save.sav");
		savewrite << lvl;
		savewrite << " ";
		savewrite << exp;
		savewrite.close();
	}

	//multiple savegame system will be added later
	void LoadSaveGame(int slot)
	{
		string filename[] = { "save.sav" };
		ifstream loadsave("save.sav");
		int loadedlvl;
		int loadedexp;
		string loadedcharacter;
		string loadedcharactertemp;
		loadsave >> loadedlvl;
		loadsave >> loadedexp;
		loadsave.close();
		ifstream loadcharacter("chr.chr");
		while (!loadcharacter.eof())
		{
			loadcharacter >> loadedcharactertemp;
			loadedcharacter.append(loadedcharactertemp);
			loadedcharacter.append(" ");
			loadedcharactertemp.erase();
		}
		loadcharacter.close();
		system("cls");
		cout << "Save Game successfully" << endl;
		if (isdebug == true)
		{
			cout << "*debug* loaded lvl: " << loadedlvl << " loaded exp: " << loadedexp << endl;
			cout << "*debug* loaded character: " << loadedcharacter << endl;
		}
		else
		{
			//
		}
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
		cout << "Character " << charactertemp << " successfully created!" << endl;
		ofstream writechr("chr.chr");
		writechr << charactertemp;
		writechr.close();
		WriteSaveFile(0, 0);
		//Add Difficulty selection!
	}

	void NewGame()
	{
		CreateCharacter();
	}

	void LoadGame()
	{
		LoadSaveGame(1);
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
		if (isbeta == true)
		{
			cout << "*The game is in beta state*" << endl;
		}
		else
		{
			//
		}
		if (isstable == false)
		{
			cout << "*The game may be unstable*" << endl;
		}
		else
		{
			//
		}
		if (isdebug == true)
		{
			cout << "*The game is running in debug mode!*" << endl;
		}
		else
		{
			//
		}
		cout << "---------------------" << endl;
		cout << "1) New Game" << endl;
		cout << "2) Load Game" << endl;
		cout << "3) Options " << endl;
		cout << "4) About" << endl;
		cout << "5) Exit" << endl;
		cout << "---------------------" << endl;
		int menuselection = 0;
		cin >> menuselection;
		switch (menuselection)
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

};

int main()
{
	Game MainGame;
	MainGame.ShowMainMenu();
}

