#include <iostream>
#include "player.h"

using namespace std;

int CheckDeath(Player players[2])
{
	if(players[0].dead == 0 && players[1].dead == 0)
		return 0;
	if(players[0].dead == 1)
		cout << players[0].name << " has perished!" << endl;
	if(players[1].dead == 1)
		cout << players[1].name << " has perished!" << endl;
	return 1;
}


int ChangeTurn(int cur_id)
{
	if(cur_id == 1)
		return 0;
	return 1;
}
