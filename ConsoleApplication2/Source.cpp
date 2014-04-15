#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const char gracz='@';
//plansza
char map[5][13]={
{'X','X','X','X','X','X','X','X','X','X','X','X','X'},
{'X',' ',' ','X',' ',' ','X','X',' ',' ','X','X','X'},
{'X',' ',' ',' ',' ',' ','X','X',' ',' ','X','X','X'},
{'X','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X','X','X','X','X','X','X','X','X','X','X','X','X'}
	
};
const char potwor='!';
const char kasa='$';

	struct position
	{
		int x;
		int y;

	};




void main()
	{
	srand (time(NULL));
	position graczpos;
	graczpos.x=1;
	graczpos.y=1;
	position oldpos;
	position kasapos;
	position potworpos;
	int pts=0;

	do
		{
			kasapos.x=(rand()%13);
			kasapos.y=(rand()%5);
		}
	while (map[kasapos.y][kasapos.x]!=' ');

	bool stop=0;	
	
	do
	{

	

		system("cls");
		cout<<"kasa: "<<pts<<endl;
		cout<<"X: "<<graczpos.x<<" Y: "<<graczpos.y<<endl;
		map[kasapos.y][kasapos.x]=kasa;
		map[graczpos.y][graczpos.x]=gracz;
		if(map[graczpos.y][graczpos.x]==map[kasapos.y][kasapos.x])
			{
				do
					{

						kasapos.x=(rand()%13);
						kasapos.y=(rand()%5);
					}
				while (map[kasapos.y][kasapos.x]!=' ');
			pts+=10;
			};

		for(int i=0;i<=4;i++)
		{
			for (int j=0;j<=12;j++)
			{
				cout<<map[i][j];
			}
		cout<<endl;
		}



		/////////////////////////////ruchy////////////////////////

		switch(getch())
			{
				//lewo
				case 'a':
				if(map[graczpos.y][graczpos.x-1]!='X')
				{
					oldpos.x=graczpos.x;
					oldpos.y=graczpos.y;
					graczpos.x--;
					map[oldpos.y][oldpos.x]=' ';
				}
				break;


				//prawo
				case 'd':
				if(map[graczpos.y][graczpos.x+1]!='X')
				{
					oldpos.x=graczpos.x;
					oldpos.y=graczpos.y;
					graczpos.x++;
					map[oldpos.y][oldpos.x]=' ';
				}
				break;

				//up
				case 'w':
				if(map[graczpos.y-1][graczpos.x]!='X')
				{
					oldpos.y=graczpos.y;
					oldpos.x=graczpos.x;
					graczpos.y--;
					map[oldpos.y][oldpos.x]=' ';
				}
				break;

				//down
				case 's':
				if(map[graczpos.y+1][graczpos.x]!='X')
				{
					oldpos.y=graczpos.y;
					oldpos.x=graczpos.x;
					graczpos.y++;
					map[oldpos.y][oldpos.x]=' ';
				}
				break;

				
				//exit
				case 'e':
				stop=1;
				break;
			}

	//////////////////////////////konic ruchow//////////////////////


	}
		while (stop != 1);



/////////////////////////////KONIEC KODU/////////////////////////
}