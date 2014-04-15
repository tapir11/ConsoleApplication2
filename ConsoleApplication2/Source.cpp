#include <iostream>
#include <conio.h>
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

position graczpos;
graczpos.x=1;
graczpos.y=1;
position oldpos;
position kasa;





void main()
	{






	bool stop=0;	
	do
	{

	

		system("cls");
		cout<<"X: "<<graczpos.x<<" Y: "<<graczpos.y<<endl;
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