#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=25;
const int height = 25;
int x,y,fruitX,fruitY, score;
int tailX[100],tailY[100];
int ntail;
enum eDirection{STOP=0, LEFT, RIGHT, TOP, DOWN};
eDirection dir;
void setup()
{
	dir = STOP;
	gameover=false;
	x = width/2;
	y = height/2;
	fruitX = rand()%x;
	fruitY = rand()%y;
	score=0;
}
void design()
{
	system("cls");
    for(int i=0;i<width;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0 || j==width-1)
			{
				cout<<"#";
			}
			else if(j==fruitX && i==fruitY)
			{
				cout<<"F";
			}
			else if(j==x && i==y)
			{
				cout<<"O";
			}
			else
			{
				bool print = false;
				for(int k=0;k<ntail;k++)
				{
					if(tailX[k]==j && tailY[k]==i)
					{
					   cout<<"o";
					   print = true;
				   }
				}
				if(!print)
				{
				   cout<<" ";
			    }
			}
		}
		cout<<endl;
	}
	for(int i=0;i<width;i++)
	{
	   cout<<"#";	
	}
	cout<<"\n"<<"Score:  "<<score<<endl;	
}
void input()
{
	if(kbhit())
	{
	     switch(getch())
		 {
		 	case 'a':
		 		dir = LEFT;
		 		break;
		 	case 'd':
		 		dir = RIGHT;
		 		break;
		 	case 'w':
		 		dir = TOP;
		 		break;
		 	case 's':
		 		dir = DOWN;
		 		break;
		 }	
	}	
}
void algo()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2x,prev2y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i=1;i<ntail;i++)
	{
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}
	switch(dir)
	{
		case TOP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
	}
	for(int i=0;i<ntail;i++)
	{
		if(tailX[i]==x && tailY[i]==y)
		{
			gameover = true;
		}
	}
	if(x<0)
	{
		x = width-1;
	}
	else if(x>width)
	{
		x = 0;
	}
	if(y<0)
	{
		y = height-1;
	}
	else if(y>height)
	{
		y = 0;
	}
	/*if(x<0 || x>width || y<0 || y>width)
	{
		gameover = true;
	}*/
	if(x==fruitX && y==fruitY)
	{
		fruitX = rand()%width;
		fruitY = rand()%height;
		score = score+10;
		ntail++;
	}
}
int main()
{
	setup();
	while(!gameover)
	{
		design();
		input();
		algo();
		Sleep(20);
	}
	
}
