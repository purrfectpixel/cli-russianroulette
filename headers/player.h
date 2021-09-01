#pragma once
#include <iostream>

using namespace std;

class Player
{
	public:
		string name;
		int dead;
};

string Naming(Player players[2], int id)
{
	cout << "Input your name, player " << id << ": ";
	getline(cin, players[id].name);
	return players[id].name;
}