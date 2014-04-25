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
	
position graczpos;
position oldpos;
position kasapos;
position potworpos;
position potworoldpos;
position endpos;




	
void move(int posy,int posx)
	{
		
		char collided=map[posy][posx]
		if (collided == ' ')
			{
				oldpos.x=graczpos.x;
				oldpos.y=graczpos.y;
				map[oldpos.y][oldpos.x]=' ';
				graczpos.x=posx;
				graczpos.y=posy;
				map[graczpos.y][graczpos.x]=gracz;
				
			}
		else if (collided  == 'X')
			{
				break;	
			}
		
		else if (collided == '$')
			{
				pts+=10;
				do
					{

						kasapos.x=(rand()%13);
						kasapos.y=(rand()%5);
					}
				while (map[kasapos.y][kasapos.x]!=' ');
				
			}
		else	if (collided == '!')
			{
				hp-=30;
				graczpos.x=1;
				graczpos.y=1;
				
			}
	}

*/

void main()
	{
	srand (time(NULL));
	graczpos.x=1;
	graczpos.y=1;
	potworpos.y=3;
	potworpos.x=4;
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
				move(graczpos.y,graczpos.x-1)
				break;



				//prawo
				case 'd':
				move(graczpos.y,graczpos.x+1)
				break;

				//up
				case 'w':
				move(graczpos.y-1,graczpos.x)
				break;

				//down
				case 's':
				move(graczpos.y+1,graczpos.x)
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
