
#include <iostream>
#include <stdlib.h>
#include "login2.cpp"
#include "tic-tac.cpp"
#include "snake.cpp"
using namespace std;

int main()
{
    int ch=0;
    int logIn=login();
    int gameNo=0;
    char gameName[100];
    if(login)
    {
        //getchar();
        while(1==1)
    {
        cout<< "\nPress:\n1:To enter game no.\n2:To enter game name:\nAny other no. to exit\n";
        cin>>ch;

        switch(ch)
        {
            case 1:cout << "Enter any no: ";
            cin>> gameNo;
            switch(gameNo)
            {
                case 1:
                    cout<< "Instructions:\n";
                    cout<<"1. The positions are assigned the respective values\n";
                    cout<<"(0,0)=0  (0,1)=1  (0,2)=2";
                    cout<<"\n(1,0)=3  (1,1)=4  (1,2)=5\n";
                    cout<<"(2,0)=6  (2,1)=7  (2,2)=8\n";
                    cout<<"2.  Player 1 is given the mark X and Player 2 is given the mark Y\n";
                    cout<<"3. To put your mark in the position enter the respective position number as mentioned previously";
                    cout<<"\n4. If you owe a row or a column or a diagonal with all your mark you win the game\n";
                    ticTacToe();
                break;

                case 2:
                    cout<<"Instructions:\n";
                    cout<<"1. The snake is depicted by circle mark\n";
                    cout<<"2. The food is depicted by F\n";
                    cout<<"3. Use keys W  A  S  D to control the snake\n W=move up  S=move down\n A=move left D=move right\n";
                    cout<<"4. The snake grows on eating the food\n";
                    cout<<"5. If the snake bumps on the wall the game will end\n";
                    snake();
                    break;

                default:cout<<"Invalid Option";
                    break;
            }
            break;

            case 2:
                cout<< "Enter any name: ";
                cin>> gameName;
                if(stricmp(gameName,"TicTac")==0)
                {
                    ticTacToe();
                }
                if(stricmp(gameName,"Snake")==0)
                {
                    snake();
                }

                else
                {
                    cout<<"Invalid Option";
                }
                break;

            default:exit(0);
        }

    }
    }

    return 0;
}
