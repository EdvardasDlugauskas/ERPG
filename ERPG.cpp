#include "stdafx.h"
#include "windows.h"
#include "fstream"
#include "stdio.h"
#include <iostream>
#include <string>
#include "stdlib.h"
#include "time.h"

using namespace std;


string gamever = "ERPG Developer preview v0.05";
string gamebuild = "D1002";
string builddate = "2017-07-25 14:44";
bool isstable = false;
bool isbeta = true;
bool isdebug = true;

class Player
{
public:
		int CurrentPlayerLvl;
		int CurrentPlayerXp;

private:
	void Debug()
	{

	}
};


class GameLogic
{
public:
	int GeneratedPlayerAttack;
	int GeneratedEnemyAttack;
	int GeneratedPreBattleEnemyHP;
	int GeneratedPreBattleEnemyMana;
	int InitialPlayerHealth;
	int InitialPlayerMana;

	void GenerateAttack(int PlayerCurrentLvl)
	{
		switch (PlayerCurrentLvl)
		{
		case 1:
			GeneratedPlayerAttack = rand() % 40 + 30;
			GeneratedEnemyAttack = rand() % 40 + 20;
			break;
		case 2:
			GeneratedPlayerAttack = rand() % 50 + 50;
			GeneratedEnemyAttack = rand() % 40 + 50;
			break;
		case 3:
			GeneratedPlayerAttack = rand() % 40 + 70;
			GeneratedEnemyAttack = rand() % 30 + 80;
			break;
		case 4:
			GeneratedPlayerAttack = rand() % 40 + 90;
			GeneratedEnemyAttack = rand() % 50 + 100;
			break;
		case 5:
			GeneratedPlayerAttack = rand() % 50 + 110;
			GeneratedEnemyAttack = rand() % 60 + 120;
			break;
		case 6:
			GeneratedPlayerAttack = rand() % 60 + 130;
			GeneratedEnemyAttack = rand() % 80 + 130;
			break;
		case 7:
			GeneratedPlayerAttack = rand() % 50 + 150;
			GeneratedEnemyAttack = rand() % 40 + 170;
			break;
		case 8:
			GeneratedPlayerAttack = rand() % 60 + 180;
			GeneratedEnemyAttack = rand() % 100 + 200;
			break;
		default:
			cout << "Game has encountered an error!" << endl;
			break;
		}
	}

	void PreBattleGeneration(int PlayerCurrentLvl)
	{
		switch (PlayerCurrentLvl)
		{
		case 1:
			GeneratedPreBattleEnemyHP = rand() % 300 + 700;
			GeneratedPreBattleEnemyMana = rand() % 100 + 50;
			InitialPlayerHealth = 1000;
			InitialPlayerMana = 150;
			break;
		case 2:
			GeneratedPreBattleEnemyHP = rand() % 300 + 800;
			GeneratedPreBattleEnemyMana = rand() % 150 + 50;
			InitialPlayerHealth = 1100;
			InitialPlayerMana = 175;
			break;
		case 3:
			GeneratedPreBattleEnemyHP = rand() % 490 + 700;
			GeneratedPreBattleEnemyMana = rand() % 50 + 150;
			InitialPlayerHealth = 1200;
			InitialPlayerMana = 200;
			break;
		case 4:
			GeneratedPreBattleEnemyHP = rand() % 200 + 1200;
			GeneratedPreBattleEnemyMana = rand() % 25 + 200;
			InitialPlayerHealth = 1300;
			InitialPlayerMana = 225;
			break;
		case 5:
			GeneratedPreBattleEnemyHP = rand() % 200 + 1300;
			GeneratedPreBattleEnemyMana = rand() % 100 + 200;
			InitialPlayerHealth = 1400;
			InitialPlayerMana = 250;
			break;
		case 6:
			GeneratedPreBattleEnemyHP = rand() % 200 + 1450;
			GeneratedPreBattleEnemyMana = rand() % 50 + 250;
			InitialPlayerHealth = 1500;
			InitialPlayerMana = 275;
			break;
		case 7:
			GeneratedPreBattleEnemyHP = rand() % 150 + 1790;
			GeneratedPreBattleEnemyMana = rand() % 100 + 300;
			InitialPlayerHealth = 1750;
			InitialPlayerMana = 300;
			break;
		case 8:
			GeneratedPreBattleEnemyHP = rand() % 300 + 2000;
			GeneratedPreBattleEnemyMana = rand() % 100 + 380;
			InitialPlayerHealth = 2000;
			InitialPlayerMana = 400;
			break;
		}
	}
};

class GameBattleScreen
{
public:
	void GenerateBattle()
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
		Player WritePlayerStats;
		WritePlayerStats.CurrentPlayerLvl = lvl;
		WritePlayerStats.CurrentPlayerXp = exp;
		if (isdebug == true)
		{
			cout << "*debug* WritePlayerStats.CurrentPlayerLvl = " << WritePlayerStats.CurrentPlayerLvl << endl;
			cout << "*debug* WritePlayerStats.CurrentPlayerXp = " << WritePlayerStats.CurrentPlayerXp << endl;
			system("pause");
		}
		else
		{
			//
		}

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
		Player WritePlayerStats;
		WritePlayerStats.CurrentPlayerLvl = loadedlvl;
		WritePlayerStats.CurrentPlayerXp = loadedexp;
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

