#include <iostream>
#include "player.h"

using namespace std;

int CheckBound(int t)
{
	if(t > 5)
		return 0;
	return t;
}

int MoveCyclinder(int b_pos, int bullets[6])
{
	int t = b_pos;
	
	bullets[b_pos] = 0;
	t++;
	t = CheckBound(t);
	bullets[t] = 1;
	return t;
}

int Roll(int b_pos, int bullets[6])
{
	cout << "Rolling the cyclinder..." << endl;
	int t = rand() % 5;
	bullets[b_pos] = 0;
	bullets[t] = 1;
	return t;
}


void Shoot(int shooter, int victim, int b_pos, int bullets[6], Player players[2])
{
	if(shooter == victim)
		cout << players[shooter].name << " points the gun to their head and..." << endl;
	else
		cout << players[shooter].name << " points the gun to " << players[victim].name << "'s head and..." << endl;

	if(bullets[0] == 1)
	{
		players[victim].dead = 1;
		cout << "BANG!" << endl;
		return;
	}	

	cout << "Nothing happened." << endl;
	return;
}