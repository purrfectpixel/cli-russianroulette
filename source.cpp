#include <iostream>
#include <string>

using namespace std;

class Player
{
	public:
		string name;
		int dead;
};

void PrintCyclinder(int bullets[6])
{
	for(int i = 0;i <= 5;i++)
		cout << bullets[i] << " ";
	cout << endl;
}

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

int ChangeTurn(int cur_id)
{
	if(cur_id == 1)
		return 0;
	return 1;
}

void Game()
{
	srand(time(NULL));
	int bullets[] = {0,0,0,0,0,0}, b_pos = rand() % 5, choice, cur_id = 0, next_id = 1, end = 0;
	bullets[b_pos] = 1;
	Player players[2];
	players[0].name = "DefaultPlayer";
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

int main()
{
	Game();
}