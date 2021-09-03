#include <iostream>
#include <string>
#include <time.h>
#include "headers/gamemode.h"


using namespace std;

int main()
{
	char choice;
	do
	{
		cout << "Welcome to RinTheTrap's Russian Roulette, choose a gamemode:\n1/ Play against AI 2/ Play against a friend";
		do
		{
			cout << "\n>";
			cin >> choice;
		}
		while(!(choice >= '1' && choice <= '2'));

		getchar();

		switch(choice)
		{
			case '1':
				AIGame();
				break;
			case '2':
				PvPGame();
				break;
		}
		
		cout << "Continue?[y/n]: \n";
		cin >> choice;
		getchar();

		if(choice != 'y')
			return 0;
		cout << string(50, '\n');
	}
	while(1);
}