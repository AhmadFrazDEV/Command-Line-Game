#include <iostream>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include<math.h>
using namespace std;

// --------------Function ----------
	void load_intro();
	void Display_intro();
	void gotoxy(int x, int y); 
	void display_maze();
	void load();
	bool silt_Vertical();
	bool silt2_Vertical();
	bool free_fall();
	bool move_silts_down();
	bool move_silts_Up();
	bool silt2_Vertical();
	bool move_silts_1_Up();
	bool move_silts_1_down();
	void moveHeroLeft();
	void moveHeroRight();
	void moveHeroDown();
	void moveHeroUp();
	bool free_fall();
	void  Fire_Right();
	void Fire_Left();
	void short_bullet(int n);
	void short_bullet_1(int n);
	void Lifting();
	bool Enemy_1();
	bool move_e1_right();
	bool move_e1_left();
	void secore();
	void print_secore();
	bool Enemy_2();
	float direction(int hx , int hy , int e2x , int e2y );
	int find();
	void load_Gmae_over();
	void display_game_over();
	void lives_counter();
	void lives_show();
	
	
// *********************************

// --------------- Array -------------

	char maze[22][71];
	char Int[16][150];
	
// ***********************************	

// --------------- Variables ----------

	int lives = 3;
	bool gamerunning = true;
	bool gamerunning_2 = true;
	bool gamerunning_free_fall = true;
	int turn = 0;
	bool temp;
	bool temp_1;
	int siltX = 1;   // X coordinate of first silt
	int siltY = 10;  // Y coordinate of first silt
	
	int silt2X = 13; // X coordinate of Second silt
	int silt2Y = 30; // Y coordinate of Second silt
	
	int turn_1 = 0;
	
	int hx = 13; // Hero X coordinate
	int hy = 62; // Hero Y coordinate
	char ch;
	int i = 2;
	char H;
	int j = 3;
	int secor = 0;

	char game[6][75];
	
// ************************************
// ---------Fire --------------
	char s=254;
	char f = 16;
	char f2 = 17;
	bool Fire_1  = false;
	// bool Fire_2 = true;
	int fX ;  // fire for Rightward
	int fY;   // fire for Rightward
	int fX1;  // fire for Leftward
	int fY1;  // fire for Leftward
	bool bullet =false;
	bool bullet_1 = false;

// ****************************
// --------------Lives ---------

	void lives_counter()
{
    lives--;
}
void lives_show()
{
    gotoxy(75, 4);
    cout << "Remaining lives:" << lives;
  
}

// ******************************
// ----------- Enemy 1 -----------

	int e1x = 3;
	int e1y = 2;
	bool Ememy_1_running;
	int turn_e = 0;
	bool temp_horizontol;
	char previousItem_horizontol = ' ';
	char e1 = 6;

//********************************
// --------------E nemy 2 ---------
	
	int e2x = 5;
	int e2y = 55;
	bool Enemy_2_running; 
	float dis[4] = {0.0 , 0.0 , 0.0 , 0.0};

//  ******************************

// ---------Enemy 3 ------------
	char e3 = 4;
	int e3x = 17;
	int e3y = 64;

// *****************************

int main()
{
// ------------------------------------------------------------	
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
// --------------------------------------------------------------   

// =============== Intro ===================
system("color B");
   load_intro();

	getch();
	Sleep(300);
	system("cls");
// *****************************************


// system("color E");
ch = i; // 	for printing of emogi
// H // For Printing Hearts

	system("cls");
	load();
	gotoxy(45 , 7);
    cout<<'$'; // Heart 
    gotoxy(45 , 13);
    cout<<'$';  // Heart
    gotoxy(3 , 3);
    cout<<'$';  //Heart
    gotoxy(21 , 5);
    cout<<'$'; //Heart
	gotoxy(6 , 16);
	cout<<'$';
	 gotoxy(hy , hx);
    cout<<ch; // Emoji
	gotoxy(e1y , e1x);
	cout<<e1;  // Emeny
	gotoxy(e2y , e2x);
	cout<<e1; // Emeny
	gotoxy(e3y , e3x);
	cout<<e1;  // Emeny
  
	while(lives > 0)
	{
		Sleep(100);
		gamerunning = silt_Vertical();
    	 gamerunning_2 = silt2_Vertical();
    	 gamerunning_free_fall = free_fall();
		 Ememy_1_running = Enemy_1(); // Enemy 1
		 Enemy_2_running = Enemy_2(); // Enemy 2
		 print_secore();
		 lives_show();
		 if(Ememy_1_running == false || Enemy_2_running == false)
		 {
		 	lives_counter();
            lives_show();
		 }
		 Lifting();
    	
    	// --------KEYS INPUT ---------

		    if (GetAsyncKeyState(VK_LEFT))
		        {
		            moveHeroLeft();
		        }
		    if (GetAsyncKeyState(VK_RIGHT))
		        {
		            moveHeroRight();
		        }
		    
			if(GetAsyncKeyState(VK_SPACE))
				{
						moveHeroUp();	
				} 

// ----------- Fire For Right ward ----------------------				
			if(GetAsyncKeyState(VK_UP))
			{
				fX = hx;
				fY = hy;
				if(bullet == false)
				{
				  Fire_Right();
				}
			}
	
			if(bullet == true)
			{
				Fire_Right();
			} 
			

// *****************************************************

// ----------- Fire For Left ward ----------------------

	if(GetAsyncKeyState(VK_DOWN))
			{
				fX1 = hx;
				fY1 = hy;
				if(bullet_1 == false)
				{
				  Fire_Left();
				}
			}
	
			if(bullet_1 == true)
			{
				Fire_Left();
			}

// *****************************************************

				    
	}
	return 0;
}

void gotoxy(int x, int y) 
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void display_maze()
{
    for (int i = 0; i < 22; i++)
    {

        for (int j = 0; j < 71; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    cout<< endl;
}
void load()
{
    fstream file;
    file.open("Frame.txt", ios::in);
    string line;
    for (int i = 0; i < 22; i++)
    {
        getline(file, line);
        for (int j = 0; j < 71; j++)
        {
            maze[i][j] = line[j];
        }
    }
    file.close();
    display_maze();
}

bool silt_Vertical()
{
	if(turn == 0)
	{
		temp = move_silts_down(); // to move silt 1 from up to down
		return temp;
	}
	if(turn == 1)
	{
		temp = move_silts_Up(); // to move silt 1 from down to up
		return temp;
	}
}

bool move_silts_down()
{
	if(maze[siltX + 1][siltY]=='.')
	{
		turn = 1;
	}
	else 
    {
		for(int i=10 ; i < 18 ; i++)
		{
			maze[siltX][i]=' ';
			gotoxy(i, siltX);
			cout<<" ";
		}
		
        siltX = siltX + 1;
        
        for(int i=10;i<18;i++)
		{
			maze[siltX][i]=s;
			gotoxy(i, siltX);
			cout<<s;
		}
    }
    return 1;
}
bool move_silts_Up()
{
	
	if(maze[siltX - 1][siltY]=='#')
	{
		turn = 0;
	}
	else
    {
    	for(int i=10 ; i < 18 ; i++)
		{
			maze[siltX][i]=' ';
			gotoxy(i, siltX);
			cout<<" ";
		}  		
        
        siltX = siltX - 1;
        
        for(int i=10 ; i<18 ; i++)
		{
			maze[siltX][i]=s;
			gotoxy(i, siltX);
			cout<<s;
		}    }
    return 1;
}

bool silt2_Vertical() //to move silt 1 one from up to down and down to up
{
	if(turn_1 == 0)
	{
		temp_1 = move_silts_1_Up(); // to move silt 1 from up to down
		return temp_1;
	}
	if(turn_1 == 1)
	{
		temp_1 = move_silts_1_down(); // to move silt 1 from down to up
		return temp_1;
	}
}

bool move_silts_1_down()  // to move silt 1 from up to down
{    
	if(maze[silt2X + 1][silt2Y]=='#')
	{
		turn_1 = 0;
	}
	else
    {
    	for(int i=30 ; i<38 ; i++)
		{
			maze[silt2X][i]=' ';
			gotoxy(i, silt2X);
			cout<<" ";
		}
		
        silt2X = silt2X + 1;
        		
        for(int i=30 ; i<38 ; i++)
		{
			maze[silt2X][i]= s;
			gotoxy(i, silt2X);
			cout<<s;
		}
    }
    return 1;
}


bool move_silts_1_Up()  // to move silt 1 from down to up
{
	if(maze[silt2X - 1][silt2Y] == '#')
	{
		turn_1 = 1;
	}
	else
    {
    	for(int i=30 ; i<38 ; i++)
		{
			maze[silt2X][i]=' ';
			gotoxy(i, silt2X);
			cout<<" ";
		}
		
        silt2X = silt2X - 1;
        
        for(int i=30 ; i<38 ; i++)
		{
			maze[silt2X][i]= s;
			gotoxy(i, silt2X);
			cout<<s;
		}
    }
    return 1;
}

void moveHeroLeft()
{
		if(maze[hx][hy - 1] == ' ')
	{
		maze[hx][hy] = ' ';
		gotoxy(hy , hx);
		cout<<" ";
		if( maze[hx][hy - 1]== '$')
		{
			secore();
		}
		hy = hy - 1;
		maze[hx][hy] =ch;
		gotoxy(hy , hx);
		cout<<ch;
		
		if(maze[hx -1][hy])
		{
			free_fall();
		}
		
	}
			if(maze[hx + 1][hy] == s)
			{
				Lifting();
			}
}
void moveHeroRight()
{
	if(maze[hx][hy + 1] == ' ')
	{
		maze[hx][hy] = ' ';
		gotoxy(hy , hx);
		cout<<" ";
		if( maze[hx][hy + 1]== '$')
		{
			secore();
		}
		hy = hy + 1;
		maze[hx][hy] = ch;
		gotoxy(hy , hx);
		cout<<ch;
		
		if(maze[hx -1][hy])
		{
			free_fall();
		}
		
		if(maze[hx + 1][hy] == s)
	{
		Lifting();
	}
	}
}
void moveHeroDown()
{
		if(maze[hx + 1][hy] == ' ')
	{
		maze[hx][hy] = ' ';
		gotoxy(hy , hx);
		cout<<" ";
		if( maze[hx + 1][hy]== '&')
		{
			secore();
		}
		hx = hx + 1;
		maze[hx][hy] =ch;
		gotoxy(hy , hx);
		cout<<ch;
	
	}
	if(maze[hx + 1][hy] == s)
	{
		Lifting();
	}
}
void moveHeroUp()
{
	
	if(maze[hx - 2][hy] == ' ')
	{
		maze[hx][hy] = ' ';
		gotoxy(hy , hx);
		cout<<" ";
		if( maze[hx - 2][hy]== '&')
		{
			secore();
		}
		hx = hx - 2;
		maze[hx][hy] =ch;
		gotoxy(hy , hx);
		cout<<ch;
		
		

		// if(GetAsyncKeyState(VK_LEFT))
		// 	    {
			    	
		// 	    	if(maze[hx][hy - 1] == ' ')
		// 			{
		// 				maze[hx][hy] = ' ';
		// 				gotoxy(hy , hx);
		// 				cout<<" ";
		// 				if( maze[hx][hy - 1]== '*')
		// {
		// 	secore();
		// }
		// 				hy = hy - 1;
		// 				maze[hx][hy] =ch;
		// 				gotoxy(hy , hx);
		// 				cout<<ch;
		// 			}
		// 		}
		// if(GetAsyncKeyState(VK_RIGHT))
		// {
		// 	if(maze[hx][hy + 1] == ' ')
		// 			{
		// 				maze[hx][hy] = ' ';
		// 				gotoxy(hy , hx);
		// 				cout<<" ";
		// 				if( maze[hx][hy + 1]== '*')
		// {
		// 	secore();
		// }
		// 				hy = hy + 1;
		// 				maze[hx][hy] =ch;
		// 				gotoxy(hy , hx);
		// 				cout<<ch;
		// 			}
	}
	// }
	// 		if(maze[hx + 1][hy] == s)
	// 		{
	// 			Lifting();
	// 		}
}

bool free_fall()
{   
	if(maze[hx + 1][hy] == s)
	{
		Lifting();
	}
    else if(maze[hx + 1][hy]=='.')
	{
		system("cls");
		load_Gmae_over();
	}
	else if((maze[hx + 1][hy]!='#') && (maze[hx + 1][hy]!='|'))
    {
		gotoxy(hy, hx);
        cout << " ";
		
        hx = hx + 1;
		maze[hx][hy] =ch;
        gotoxy(hy, hx);
        cout << ch;
    }
	
	
    
    return 1;
}

void Fire_Right()
{
	if(maze[fX][fY + 1] == ' ')
	{	
		bullet = true;
		fY  = fY + 1;
		short_bullet(1);
	}
	
	else 
	{
		bullet = false;
	}

}

void short_bullet(int n)
{

	if(maze[fX][fY + 1] == ' ')
	{
		
		maze[fX][fY] = ' ';
		gotoxy(fY , fX);
		cout<<" ";
		fY = fY + 1;
		maze[fX][fY] = f;
		gotoxy(fY , fX);
		cout<<f;
		if(maze[fX][fY + 1] == '#' || maze[fX][fY + 1] == '|' || maze[fX][fY + 1] == e1)
			{
				gotoxy(fY , fX);
				cout<<" ";
			}
		
		maze[fX][fY] = ' ';
		fY = fY - 1;
		gotoxy(fY , fX);
		cout<<" ";
		(fX , fY);
	}
	
}

void Fire_Left()
{
	if(maze[fX1][fY1 - 1] == ' ')
	{
		bullet_1 = true;
		fY1  = fY1 - 1;
		short_bullet_1(1);
	}

	else
	{
		bullet_1 = false;
	}

}

void short_bullet_1(int n)
{
	if(maze[fX1][fY1 - 1] == ' ')
	{
		
		maze[fX1][fY1] = ' ';
		gotoxy(fY1 , fX1);
		cout<<" ";
		fY1 = fY1 - 1;
		maze[fX1][fY1] = f;
		gotoxy(fY1 , fX1);
		cout<<f2;
		if(maze[fX1][fY1 - 1] == '#' || maze[fX1][fY1 - 1] == '|' || maze[fX][fY + 1] == e1)
			{
				gotoxy(fY1 , fX1);
				cout<<" ";
			}
		
		maze[fX1][fY1] = ' ';
		fY1 = fY1 + 1;
		gotoxy(fY1 , fX1);
		cout<<" ";
	(fX1 , fY1);
	
	}
}


void Lifting()
{
	
	if(maze[hx + 1][hy] == s)
	{
		
		maze[hx][hy] = ' ';
		gotoxy(hy , hx);
		cout<<" ";
		hx = hx - 1;
		gotoxy(hy , hx);
		cout<< ch;
	}
}

bool Enemy_1()
{
	if (turn_e == 0)
    {
        temp_horizontol = move_e1_right();
        return temp_horizontol;
    }
    if (turn_e == 1)
    {
        temp_horizontol = move_e1_left();
        return temp_horizontol;
    }
}

bool move_e1_right()
{
	if (maze[e1x][e1y + 1] == ' ' || maze[e1x][e1y + 1] == ch)
    {

        maze[e1x][e1y] = ' ';
        gotoxy(e1y , e1x);
        cout << ' ';
        e1y = e1y + 1;
        previousItem_horizontol = maze[e1x][e1y];
        maze[e1x][e1y] = ch;
        gotoxy(e1y, e1x);
        cout <<e1;
		if(maze[e1x][e1y] == H)
		{
			secore();
		}
    }
	

    if (maze[e1x][e1y + 1] == '#')
    {
        previousItem_horizontol = ' ';
        turn_e = 1;
    }
    if (previousItem_horizontol != ch)
    {
        return true;
    }
	
}
bool move_e1_left()
{
	if (maze[e1x][e1y - 1] == ' ' || maze[e1x][e1y - 1] == ch)
    {

        maze[e1x][e1y] = ' ';
        gotoxy(e1y , e1x);
        cout << ' ';
        e1y = e1y - 1;
        previousItem_horizontol = maze[e1x][e1y];
        maze[e1x][e1y] = ch;
        gotoxy(e1y, e1x);
        cout <<e1;
	if(maze[e2x][e2y] == f || maze[e2x][e2y] == f2)
					{
						secore();
					}
    }



    if (maze[e1x][e1y - 1] == '#')
    {
        previousItem_horizontol = ' ';
        turn_e = 0;
    }
    if (previousItem_horizontol != ch)
    {
        return true;
    }
		
}

void secore()
{
	secor++;
}
void print_secore()
{
	  gotoxy(80 , 13);
	cout<<"SECORE > > >"<< " "<<secor;
}
float direction(int hx , int hy , int e2x , int e2y )
{
    float d = sqrt(pow((e2x - hx), 2) + (pow((e2y - hy), 2)));
    return d;
}

int find()
{
    int small = dis[0];
    int s_idx = 0;
    for(int i=0 ; i<4 ; i++)
    {
        if(dis[i] < small)
        {
            small = dis[i];
            s_idx = i;
        }
    }
    return s_idx;
}
bool Enemy_2()
{
	dis[0]  = direction(hx , hy , e2x , e2y - 1);
    dis[1]  = direction(hx , hy , e2x , e2y + 1);
    dis[2]  = direction(hx , hy , e2x - 1 , e2y);
    dis[3]  = direction(hx , hy , e2x + 1 , e2y);
    


    int small_idx = find();
    if(small_idx == 0) // Left Ward
    {
		if(maze[e2x][e2y - 1] == ' ' || maze[e2x][e2y - 1] == ch)
		{
			maze[e2x][e2y] = ' ';
			gotoxy(e2y , e2x);
			cout<<" ";
			
			e2y = e2y - 1;
			gotoxy(e2y , e2x);
			cout<<e1;
			if(maze[e2x][e2y] == ch)
					{
						return false;
					}
			
		}
		if(maze[e2x][e2y - 1] == '#' || maze[e2x][e2y - 1] == '|')
			{

			   if(maze[e2x][e2y + 1] == ' ')
					{
						maze[e2x][e2y] = ' ';
						gotoxy(e2y , e2x);
						cout<<" ";
						e2y = e2y  + 3;
						gotoxy(e2y , e2x);
						cout<<e1;
										
					}
				if(maze[e2x +1][e2y] == ' ')
					{
						maze[e2x][e2y] = ' ';
						gotoxy(e2y , e2x);
						cout<<" ";
						e2x = e2x  + 3;
						gotoxy(e2y , e2x);
						cout<<e1;
										
					}
				
					
			}
		
		return 1;
        
    }
    if(small_idx == 1) // Right Ward
    {
        if(maze[e2x][e2y + 1] == ' ' || maze[e2x][e2y + 1] == ch)
		{
			maze[e2x][e2y] = ' ';
			gotoxy(e2y , e2x);
			cout<<" ";
			e2y = e2y + 1;
			gotoxy(e2y , e2x);
			cout<<e1;
				if(maze[e2x][e2y] == ch)
				{
					return false;
				}
		}
		if(maze[e2x][e2y + 1] == '#' || maze[e2x][e2y + 1] == '|')
			{
				if(maze[e2x +1][e2y] == ' ')
						{
							maze[e2x][e2y] = ' ';
							gotoxy(e2y , e2x);
							cout<<" ";
							e2x = e2x  + 3;
							gotoxy(e2y , e2x);
							cout<<e1;
											
						}
				if(maze[e2x][e2y - 1] == ' ' )
						{
							maze[e2x][e2y] = ' ';
							gotoxy(e2y , e2x);
							cout<<" ";
							e2y = e2y  - 3;
							gotoxy(e2y , e2x);
							cout<<e1;
											
						}
			}
	
				return 1;
	}


    if(small_idx == 2) // Up ward 
    {
        if(maze[e2x - 1][e2y] == ' ' || maze[e2x - 1][e2y] == ch)
		{
			maze[e2x][e2y] = ' ';
			gotoxy(e2y , e2x);
			cout<<" ";
			e2x = e2x - 1;
			gotoxy(e2y , e2x);
			cout<<e1;
					if(maze[e2x][e2y] == ch)
				{
					return false;
				}
			
		}
		if(maze[e2x - 1][e2y] == '#' || maze[e2x - 1][e2y] == '|')
			{
				if(maze[e2x][e2y - 1] == ' ' )
						{
							maze[e2x][e2y] = ' ';
							gotoxy(e2y , e2x);
							cout<<" ";
							e2y = e2y  - 3;
							gotoxy(e2y , e2x);
							cout<<e1;
											
						}
				if(maze[e2x][e2y + 1] == ' ')
						{
							maze[e2x][e2y] = ' ';
							gotoxy(e2y , e2x);
							cout<<" ";
							e2y = e2y  + 3;
							gotoxy(e2y , e2x);
							cout<<e1;
											
						}
			}

				return 1;
	}

    
    if(small_idx == 3) // Down Ward
    {
        if(maze[e2x + 1][e2y] == ' '  || maze[e2x - 1][e2y] == ch) 
		{
			maze[e2x][e2y] = ' ';
			gotoxy(e2y , e2x);
			cout<<" ";
			e2x = e2x + 1;
			gotoxy(e2y , e2x);
			cout<<e1;
		 if(maze[e2x][e2y] == ch)
				{
					return false;
				}
		}
		else if(maze[e2x + 1][e2y] == '#' || maze[e2x + 1][e2y] == '|')
			{
					if(maze[e2x][e2y - 1] == ' ' )
						{
							maze[e2x][e2y] = ' ';
							gotoxy(e2y , e2x);
							cout<<" ";
							e2y = e2y  - 3;
							gotoxy(e2y , e2x);
							cout<<e1;
											
						}
				if(maze[e2x][e2y + 1] == ' ')
						{
							maze[e2x][e2y] = ' ';
							gotoxy(e2y , e2x);
							cout<<" ";
							e2y = e2y  + 3;
							gotoxy(e2y , e2x);
							cout<<e1;
											
						}
			}
		
    
    	return 1;
    }

}

void load_Gmae_over()
{
	
	fstream gameOver;
	string line_1;
	gameOver.open("game_over.txt" , ios::in);
	  for (int i = 0; i < 7; i++)
    {
        getline(gameOver , line_1);
        for (int j = 0; j < 76; j++)
        {
            game[i][j] = line_1[j];
        }
    }
	gameOver.close();
	display_game_over();
}
void display_game_over()

{
	 for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 76; j++)
        {
            cout << game[i][j];
        }
        cout << endl;
    }

}

void load_intro()
{
	fstream Intro;
	string line_2;
	Intro.open("Intro.txt" , ios::in);
	   for (int i = 0; i < 16; i++)
    {
        getline(Intro, line_2);
        for (int j = 0; j < 150; j++)
        {
            Int[i][j] = line_2[j];
        }
    }
	Intro.close();
	Display_intro();
}
void Display_intro()
{
	   for (int i = 0; i < 16; i++)
    {

        for (int j = 0; j < 150; j++)
        {
            cout << Int[i][j];
        }
        cout << endl;
    }

    cout<< endl;
}