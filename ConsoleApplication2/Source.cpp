#include <iostream>
#include <conio.h>
using namespace std;


void main()
	{

	const char gracz='@';


	//plansza
	char map[5][13]={
	{'X','X','X','X','X','X','X','X','X','X','X','X','X'},
	{'X',' ',' ','X',' ',' ','X','X',' ',' ','X','X','X'},
	{'X',' ',' ',' ',' ',' ','X','X',' ',' ','X','X','X'},
	{'X','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X','X','X','X','X','X','X','X','X','X','X','X','X'}
	
	
	};


	struct position
	{
		int x;
		int y;

	};

	position graczpos;
	graczpos.x=1;
	graczpos.y=1;
	position oldpos;
	//po chuj mu wartosci poczatkowe? bez nie dziala
	oldpos.x=1;
	oldpos.y=1;

	///////////ruchy/////


////////////////////////koniec ruchow///////////////////////////




		int s=0;

	bool stop=0;	
	do
	{

	

		system("cls");
		map[graczpos.y][graczpos.x]=gracz;


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
				if(graczpos.x-1!='X')
				{
					oldpos.x=graczpos.x;
					graczpos.x--;
					map[graczpos.y][oldpos.x]=' ';
				}
				break;


				//prawo
				case 'd':
				if(graczpos.x+1!='X')
				{
					oldpos.x=graczpos.x;
					graczpos.x++;
					map[graczpos.y][oldpos.x]=' ';
				}
				break;

				//up
				case 'w':
				if(graczpos.y-1!='X')
				{
					oldpos.y=graczpos.y;
					graczpos.y--;
					map[oldpos.y][graczpos.x]=' ';
				}
				break;

				//down
				case 's':
				if(graczpos.y+1!='X')
				{
					oldpos.y=graczpos.y;
					graczpos.y++;
					map[oldpos.y][graczpos.x]=' ';
				}
				break;

				
				//exit
				case 'e':
				stop=1;
				break;
			}

	//////////////////////////////konic ruchow//////////////////////

		s++;
		cout<<s<<endl;
	}
		while (stop != 1);



/////////////////////////////KONIEC KODU/////////////////////////
}