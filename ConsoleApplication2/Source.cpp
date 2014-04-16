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
{'X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X','X','X','X','X','X','X','X','X','X','X','X','X'}
	
};
const char potwor='!';
const char kasa='$';
const char kurwadzialaj='e';

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
	position potworoldpos;
	potworpos.y=3;
	potworpos.x=4;
	position endpos;
	endpos.x=9;
	endpos.y=1;
	int pts=0;
	int hp=100;
	bool lewak=0;
	bool win=0;

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
		cout<<"zycie: "<<hp<<endl;
		cout<<"X: "<<graczpos.x<<" Y: "<<graczpos.y<<endl;
		cout<<"X: "<<potworpos.x<<" Y: "<<potworpos.y<<endl;



		map[potworpos.y][potworpos.x]=potwor;
		map[kasapos.y][kasapos.x]=kasa;
		map[graczpos.y][graczpos.x]=gracz;
		map[endpos.y][endpos.x]=kurwadzialaj;

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


	
/////////  @UP jak wstawie to wyzej to sie pierdoli. kurwa czemu?




/////////////////////////ruch potwora////////////////////
	if(lewak==0)
	{
		if (map[potworpos.y][potworpos.x+1]!='X')
		{
			potworoldpos.x=potworpos.x;
			potworoldpos.y=potworpos.y;
			potworpos.x++;
			map[potworoldpos.y][potworoldpos.x]=' ';
		}
		else
		{
		lewak=1;
		potworoldpos.x=potworpos.x;
		potworoldpos.y=potworpos.y;
		potworpos.x--;
		map[potworoldpos.y][potworoldpos.x]=' ';
		}

	}
	else
	{
		if (map[potworpos.y][potworpos.x-1]!='X')
		{
			potworoldpos.x=potworpos.x;
			potworoldpos.y=potworpos.y;
			potworpos.x--;
			map[potworoldpos.y][potworoldpos.x]=' ';
		}
		else
		{
		lewak=0;
		potworoldpos.x=potworpos.x;
		potworoldpos.y=potworpos.y;
		potworpos.x++;
		map[potworoldpos.y][potworoldpos.x]=' ';
		}
		
	}



/////////////////////koniec ruchu potwora//////////////////

	if(map[graczpos.y][graczpos.x]==map[potworpos.y][potworpos.x])
	{
		graczpos.y=1;
		graczpos.x=1;
		hp-=30;
		if(hp<=0)
		{
			stop=1;
			break;
		}
		

	}





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

	if(map[graczpos.y][graczpos.x]==map[endpos.y][endpos.x])
		{
			win=1;
			break;
		}










	}
		while (stop != 1);


if (hp<=0)
cout<<"umarles hahahhaha \n";

//if(stop!=1)
//cout<<"zdobyles "<<pts<<" kasy \n";

if (win==1)
cout<<"ukonczyles gre z wyniekiem: "<<pts<<"$ \n";

getch();
/////////////////////////////KONIEC KODU/////////////////////////
}