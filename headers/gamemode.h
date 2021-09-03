#include <iostream>
#include "player.h"
#include "gamecontrol.h"
#include "revolver.h"

using namespace std;

void AIGame()
{
	srand(time(NULL));
	int bullets[] = {0,0,0,0,0,0}, b_pos = rand() % 5, choice, cur_id = 0, next_id = 1, end = 0;
	bullets[b_pos] = 1;
	Player players[2];
	players[0].name = Naming(players,0);
	players[1].name = "AI";
	players[0].dead = 0;
	players[1].dead = 0;

	do
	{
		if(cur_id == 1)
			next_id = 0;
		else
			next_id = 1;

		//PrintCyclinder(bullets);
		if(cur_id == 0)
		{
			do
			{
				cout << players[cur_id].name << ", make a choice.\n1/Shoot yourself 2/Roll 3/Shoot opponent\n";
				cin >> choice;
			}
			while(!(choice >= 1 && choice <= 3));
		}
		else
			choice = (rand() % 3) + 1;

		if(cur_id == 0)
			cout << string(50, '\n');

		switch(choice)
		{
			case 1:
				Shoot(cur_id, cur_id, b_pos, bullets, players);
				b_pos = MoveCyclinder(b_pos, bullets);
				break;
			case 2:
				b_pos = Roll(b_pos, bullets);
				//PrintCyclinder(bullets);
				Shoot(cur_id, cur_id, b_pos, bullets, players);
				break;
			case 3:
				Shoot(cur_id, next_id, b_pos, bullets, players);
				b_pos = MoveCyclinder(b_pos, bullets);
				if(players[next_id].dead == 1)
					break;
				Shoot(cur_id, cur_id, b_pos, bullets, players);
				b_pos = MoveCyclinder(b_pos, bullets);
				break;
		}
		//PrintCyclinder(bullets);
		end = CheckDeath(players);

		if(end != 1)
			cur_id = ChangeTurn(cur_id);
	}
	while(end == 0);
}

void PvPGame()
{
	srand(time(NULL));
	int bullets[] = {0,0,0,0,0,0}, b_pos = rand() % 5, choice, cur_id = 0, next_id = 1, end = 0;
	bullets[b_pos] = 1;
	Player players[2];
	players[0].name = Naming(players,0);
	players[1].name = Naming(players,1);
	players[0].dead = 0;
	players[1].dead = 0;

	do
	{
		if(cur_id == 1)
			next_id = 0;
		else
			next_id = 1;

		//PrintCyclinder(bullets);
		do
		{
			cout << players[cur_id].name << ", make a choice.\n1/Shoot yourself 2/Roll 3/Shoot opponent\n";
			cin >> choice;
		}
		while(!(choice >= 1 && choice <= 3));

		cout << string(50, '\n');

		switch(choice)
		{
			case 1:
				Shoot(cur_id, cur_id, b_pos, bullets, players);
				b_pos = MoveCyclinder(b_pos, bullets);
				break;
			case 2:
				b_pos = Roll(b_pos, bullets);
				//PrintCyclinder(bullets);
				Shoot(cur_id, cur_id, b_pos, bullets, players);
				break;
			case 3:
				Shoot(cur_id, next_id, b_pos, bullets, players);
				b_pos = MoveCyclinder(b_pos, bullets);
				if(players[next_id].dead == 1)
					break;
				Shoot(cur_id, cur_id, b_pos, bullets, players);
				b_pos = MoveCyclinder(b_pos, bullets);
				break;
		}
		//PrintCyclinder(bullets);
		end = CheckDeath(players);

		if(end != 1)
			cur_id = ChangeTurn(cur_id);
	}
	while(end == 0);
}