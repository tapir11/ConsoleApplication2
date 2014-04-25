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
<<<<<<< HEAD
int pts=0;
int hp=100;
bool win=0;




	
void move(int posy,int posx)
	{
		
		char collided=map[posy][posx];
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
			}

		else if (collided  == 'e')
			{	
				win=1;
				oldpos.x=graczpos.x;
				oldpos.y=graczpos.y;
				map[oldpos.y][oldpos.x]=' ';
				graczpos.x=posx;
				graczpos.y=posy;
				map[graczpos.y][graczpos.x]=gracz;
			}
		
		else if (collided == '$')
			{
				
				oldpos.x=graczpos.x;
				oldpos.y=graczpos.y;
				map[oldpos.y][oldpos.x]=' ';
				graczpos.x=posx;
				graczpos.y=posy;
				map[graczpos.y][graczpos.x]=gracz;
				
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
				oldpos.x=graczpos.x;
				oldpos.y=graczpos.y;
				map[oldpos.y][oldpos.x]=' ';
				graczpos.x=1;
				graczpos.y=1;
				
			}
	}
=======


>>>>>>> 86431656c0cbee981d77d962ca37806c21affabe


	
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
	bool lewak=0;
	

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


		map[graczpos.y][graczpos.x]=gracz;
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




		


		/////////////////////////////ruchy////////////////////////

		switch(getch())
			{
				//lewo
				case 'a':
<<<<<<< HEAD
				move(graczpos.y,graczpos.x-1);
=======
				move(graczpos.y,graczpos.x-1)
>>>>>>> 86431656c0cbee981d77d962ca37806c21affabe
				break;



				//prawo
				case 'd':
<<<<<<< HEAD
				move(graczpos.y,graczpos.x+1);
=======
				move(graczpos.y,graczpos.x+1)
>>>>>>> 86431656c0cbee981d77d962ca37806c21affabe
				break;

				//up
				case 'w':
<<<<<<< HEAD
				move(graczpos.y-1,graczpos.x);
=======
				move(graczpos.y-1,graczpos.x)
>>>>>>> 86431656c0cbee981d77d962ca37806c21affabe
				break;

				//down
				case 's':
<<<<<<< HEAD
				move(graczpos.y+1,graczpos.x);
=======
				move(graczpos.y+1,graczpos.x)
>>>>>>> 86431656c0cbee981d77d962ca37806c21affabe
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













	if(win==1)
		break;


	}
		while (stop != 1);


if (hp<=0)
cout<<"umarles hahahhaha \n";


if (win==1)
cout<<"ukonczyles gre z wyniekiem: "<<pts<<"$ \n";

getch();
/////////////////////////////KONIEC KODU/////////////////////////
}
