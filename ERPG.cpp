#include "stdafx.h"
#include "windows.h"
#include "fstream"
#include "stdio.h"
#include <iostream>
#include <string>
#include "stdlib.h"
#include "time.h"

using namespace std;


//string gamever = "ERPG Developer preview v0.06";
string gamever = "ERPG indev v0.06";
string gamebuild = "I0021";
string builddate = "2017-07-25 23:12";
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

	string PlayerCharacter;
	string PlayerCharactersName;

	int playerslvlcurrent;
	int playersexpcurrent;

	int GeneratedPlayerAttack [8] = { rand() % 40 + 30 , rand() % 50 + 50 , rand() % 40 + 70 , rand() % 40 + 90 , rand() % 50 + 110 , rand() % 60 + 130, 
		rand() % 50 + 150 , rand() % 60 + 180 };

	int GeneratedEnemyAttack [8] = { rand() % 40 + 20, rand() % 40 + 50 , rand() % 30 + 80 , rand() % 50 + 100 , rand() % 60 + 120 , rand() % 80 + 130,
		rand() % 30 + 150 , rand() % 100 + 200 };

	int GeneratedPreBattleEnemyHP [8] = { rand() % 300 + 700 , rand() % 300 + 800 , rand() % 490 + 700 , rand() % 200 + 1200 , rand() % 200 + 1300 , rand() % 200 + 1450,
		rand() % 150 + 1790 , rand() % 300 + 2000 };

	int GeneratedPreBattleEnemyMana [8] = { rand() % 100 + 50 , rand() % 150 + 50 , rand() % 50 + 150 , rand() % 25 + 200 , rand() % 100 + 200 , rand() % 50 + 250,
		rand() % 100 + 300 , rand() % 100 + 380 };

	int InitialPlayerHealth [8] = { 1000 , 1100 , 1200 , 1300 , 1400 , 1500 , 1750 , 2000 };

	int InitialPlayerMana [8] = { 150 , 175 , 200 , 225 , 250 , 275 , 300 , 400 };

	void GenerateAttack(int PlayerCurrentLvl)
	{

	}

	void PreBattleGeneration(int PlayerCurrentLvl)
	{

	}
};

class GameBattleScreen
{

public:

	int PlayerHpAfterUpdate;
	int PlayersManaAfterUpdate;
	int EnemysHpAfterUpdate;
	int EnemysManaAfterUpdate;

	int ExitIfError(int status)
	{
		return status;
	}

	void GenerateBattle(int StartingEnemysHealth, int StartingEnemysMana)
	{
		system("cls");
		GameLogic GL;
		cout << "Battle: " << GL.PlayerCharactersName << "( "<<GL.PlayerCharacter<<" ) "<<GL.playerslvlcurrent<<" lvl "<<GL.playersexpcurrent<<" exp"<< endl;
		cout << "Opponent: Opponent" << GL.playerslvlcurrent << " lvl" << endl;
		cout << "=====================================" << endl;
		cout << GL.PlayerCharactersName << endl;
		cout << "-------------------------------------" << endl;
		cout << GL.PlayerCharactersName << "'s Health: " <<PlayerHpAfterUpdate<<" / "<< GL.InitialPlayerHealth << endl;
		cout << GL.PlayerCharactersName << "'s Mana: " << PlayersManaAfterUpdate << " / " << GL.InitialPlayerMana << endl;
		cout << "=====================================" << endl;
		cout << "Enemy's Health: " << EnemysHpAfterUpdate << " / " << StartingEnemysHealth << endl;
		cout << "Enemy's Mana: " << EnemysManaAfterUpdate << " / " << StartingEnemysMana << endl;
		cout << "=====================================" << endl;
		Sleep(1000);
		int TakenDagameFromPlayer = GL.GeneratedPlayerAttack[GL.playerslvlcurrent];
		int TakenDamageFromEnemy = GL.GeneratedEnemyAttack[GL.playerslvlcurrent];
		cout << GL.PlayerCharactersName << "( " << GL.PlayerCharacter << " ) " << " did " << TakenDagameFromPlayer << " damage!" << endl;
		PlayerHpAfterUpdate = PlayerHpAfterUpdate - TakenDamageFromEnemy;
		EnemysHpAfterUpdate = EnemysHpAfterUpdate - TakenDagameFromPlayer;
		Sleep(1000);
		cout << "Opponent: Opponent did: " << TakenDamageFromEnemy << " damage!" << endl;
		Sleep(1000);
		if ((PlayerHpAfterUpdate < 1) || (EnemysHpAfterUpdate < 1))
		{
			cout << "*debug* Game ended, im too tired to complete the section that decides who wins :DD" << endl;
			system("pause");
			ExitIfError(0);
		}
		else
		{
			GenerateBattle(StartingEnemysHealth, StartingEnemysMana);
		}
	}

	void PrepareBattle()
	{
		GameLogic GetEnemysStats;
		int StartingEnemysHealth = GetEnemysStats.GeneratedPreBattleEnemyHP[GetEnemysStats.playerslvlcurrent];
		int StartingEnemysMana = GetEnemysStats.GeneratedPreBattleEnemyMana[GetEnemysStats.playerslvlcurrent];
		system("cls");
		cout << "Loading..." << endl;
		Sleep(1500);
		GenerateBattle(StartingEnemysHealth, StartingEnemysMana);
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
		GameLogic GL3;
		WritePlayerStats.CurrentPlayerLvl = lvl;
		WritePlayerStats.CurrentPlayerXp = exp;
		GL3.playersexpcurrent = exp;
		GL3.playerslvlcurrent = lvl;
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
		string loadedcharactersname;
		string loadedchartemp;
		loadcharacter.close();
		ifstream loadcharname("charname.nam");
		while (!loadcharname.eof())
		{
			loadcharname >> loadedchartemp;
			loadedcharactersname.append(loadedchartemp);
			loadedcharactersname.append(" ");
			loadedchartemp.erase();
		}
		loadcharname.close();
		Player WritePlayerStats;
		WritePlayerStats.CurrentPlayerLvl = loadedlvl;
		WritePlayerStats.CurrentPlayerXp = loadedexp;
		GameLogic GL2;
		GL2.playersexpcurrent = loadedexp;
		GL2.playerslvlcurrent = loadedlvl;
		GL2.PlayerCharacter = loadedcharacter;
		GL2.PlayerCharactersName = loadedcharactersname;
		system("cls");
		cout << "Save Game successfully" << endl;
		if (isdebug == true)
		{
			cout << "*debug* loaded lvl: " << GL2.playerslvlcurrent << " loaded exp: " << GL2.playersexpcurrent << endl;
			cout << "*debug* loaded character: " << GL2.PlayerCharacter << endl;
			cout << "*debug* loaded characters name: " << GL2.PlayerCharactersName << endl;
		}
		else
		{
			//
		}
		GameBattleScreen GB;
		GB.PrepareBattle();
	}

	void CreateCharacter()
	{
		GameLogic GL1;
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
		cout << "" << endl;
		cout << "Create name for your character: ";
		string inputname;
		getline(cin, inputname);
		GL1.PlayerCharactersName = inputname;
		GL1.PlayerCharacter = charactertemp;
		ofstream writechr("chr.chr");
		writechr << charactertemp;
		writechr.close();
		ofstream charnamewrite("charname.nam");
		charnamewrite << inputname;
		charnamewrite.close();
		WriteSaveFile(0, 0);
		GameBattleScreen GB;
		GB.PrepareBattle();
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

	int ExitGame()
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
			ExitGame();
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

