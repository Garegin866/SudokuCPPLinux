#include <iostream>
#include <bits/stdc++.h>
#include "conio.h"
#include <chrono>
#include <thread>

////Colors////
#define RED  "\x1B[31m"
#define SYSTEXT "\x1B[96m"
#define BORDER "\x1B[36;1m"
#define innerBORDER "\x1B[37;0m"
#define defPoint "\x1B[97m"
#define GRN  "\x1B[92m"
#define ACTIVE  "\x1B[93m"
#define BOLD "\x1B[1m"
//////////////

using namespace std;

/////Variables////
enum eDir {n1,n2,n3,n4,n5,n6,n7,n8,n9, STOP, LEFT, RIGHT, UP, DOWN };
eDir dir;
int dirX , dirY ;
bool gameOver = false;
int gameMode = 0;
const int n = 9;
int tableForCheck[n][n] = {{0, 4, 5, 0, 0, 0, 7, 8, 0},
                   {6, 0, 0, 0, 0, 0, 0, 0, 9},
                   {0, 0, 0, 1, 8, 9, 0, 0, 0},
                   {0, 0, 2, 0, 6, 0, 1, 0, 0},
                   {0, 0, 6, 5, 0, 7, 4, 0, 0},
                   {0, 5, 0, 2, 0, 8, 0, 3, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 3, 0, 0, 0, 0, 0, 6, 0},
                   {0, 0, 0, 9, 3, 4, 0, 0, 0}};

int table[n][n] = {{1, 4, 5, 2, 0, 0, 7, 8, 0},
                           {6, 0, 0, 0, 0, 0, 0, 0, 9},
                           {0, 0, 0, 1, 8, 9, 0, 0, 0},
                           {0, 0, 2, 0, 6, 0, 1, 0, 0},
                           {0, 0, 6, 5, 0, 7, 4, 0, 0},
                           {0, 5, 0, 2, 0, 8, 0, 3, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 3, 0, 0, 0, 0, 0, 6, 0},
                           {0, 0, 0, 9, 3, 4, 0, 0, 0}};


int easyTable[n][n] = {{0, 4, 5, 0, 0, 0, 7, 8, 0},
                   {6, 0, 0, 0, 0, 0, 0, 0, 9},
                   {0, 0, 0, 1, 8, 9, 0, 0, 0},
                   {0, 0, 2, 0, 6, 0, 1, 0, 0},
                   {0, 0, 6, 5, 0, 7, 4, 0, 0},
                   {0, 5, 0, 2, 0, 8, 0, 3, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 3, 0, 0, 0, 0, 0, 6, 0},
                   {0, 0, 0, 9, 3, 4, 0, 0, 0}};
/*
int easyTable[n][n] = {{9, 4, 5, 3, 2, 6, 7, 8, 1},
                   {6, 1, 8, 7, 4, 5, 3, 2, 9},
                   {2, 7, 3, 1, 8, 9, 5, 4, 6},
                   {7, 9, 2, 4, 6, 3, 1, 5, 8},
                   {3, 8, 6, 5, 0, 7, 4, 0, 2},
                   {1, 5, 4, 2, 9, 8, 6, 3, 7},
                   {4, 2, 9, 6, 5, 0, 8, 7, 3},
                   {5, 3, 1, 8, 7, 2, 0, 6, 4},
                   {8, 6, 7, 9, 3, 4, 2, 1, 5}};*/


//////////////////


//////Function declarations//////

void Input() {

    if (_kbhit()) {
        switch (getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
            case '1':
                dir = n1;
                break;
            case '2':
                dir = n2;
                break;
            case '3':
                dir = n3;
                break;
            case '4':
                dir = n4;
                break;
            case '5':
                dir = n5;
                break;
            case '6':
                dir = n6;
                break;
            case '7':
                dir = n7;
                break;
            case '8':
                dir = n8;
                break;
            case '9':
                dir = n9;
                break;
        }
    }else{
        dir = STOP;
    }
}

///////Global//////////

void SelectMode(){
    cout << "\033[2J\033[1;1H";
    cout<< BOLD;

    cout<<GRN "Select game mode..."<<endl;
    cout<<SYSTEXT "[1]" << GRN "Easy Mode" <<endl;
    cout<<BORDER "[2]" << GRN "Hard Mode"<<endl;
    do{ cout<< defPoint "Select: "; cin>>gameMode;}while(!((gameMode == 1) || (gameMode == 2)));

}


///////////////////////

///////Hard Mode///////

bool checkRow(int v ,int r){
    if(count(table[r], table[r] + n, v)==1){
        return true;
    }
    return false;
}

bool checkCol(int v , int c){
    int count = 0;
    for(int j = 0; j < n; j++){
        if(table[j][c] == v){count++;}
    }

    if(count == 1){
        return true;
    }
    return false;
}


void Draw(int arr[n][n]){
    cout << "\033[2J\033[1;1H";
    cout<<dirX << " " << dirY;
    this_thread::sleep_for(chrono::milliseconds(5));
    cout<< "  ";
    cout<<endl;

    for(int i = 0; i < n; i++){
        if(i == 0 || i == 3 || i == 6 ){
            cout<< BORDER " ###########################################";
            cout<<endl;
        }else if((i >= 1) || (i <= 8)  ){
            cout<< BORDER " #" << innerBORDER "⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺ " BORDER "#" innerBORDER "⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺ "  BORDER "#" innerBORDER "⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺  " << BORDER "#";

            cout<<endl;
        }
        for(int j = 0; j < n; j++) {


            //karmir sahmannery
            if ((j == 0) || (j == 3) || (j == 6)) {
                cout << BORDER " # ";
            } else {
                cout << innerBORDER " ︱ ";
            }
            //erb der arjeq chka
            if (arr[i][j] == 0) {
                if((dirX == j) && ( dirY == i)){
                    cout<<ACTIVE BOLD << "•";
                }else {
                    cout << defPoint BOLD "•";
                }

            } else if (arr[i][j] != 0 && tableForCheck[i][j] != 0) {

                if((dirX == j) && ( dirY == i)){
                    cout<<ACTIVE << arr[i][j];
                }else {
                    cout << SYSTEXT << arr[i][j];
                }
            } else {

                if((dirX == j) && ( dirY == i)){
                    cout<<ACTIVE << arr[i][j];
                }else {
                    cout << GRN << arr[i][j];
                }
            }

        }

        cout<< BORDER " # ";
        cout<<endl;



    }
    cout<< BORDER " ###########################################";
    cout<<endl<<endl;

}

void Logic() {

    switch (dir) {
        case LEFT:
            dirX--;
            break;
        case RIGHT:
            dirX++;
            break;
        case UP:
            dirY--;
            break;
        case DOWN:
            dirY++;
        case n1:
            if(!tableForCheck[dirY][dirX] == 0){
                break;
            }
            else{
                table[dirY][dirX] = 1;
            }
            break;
        case STOP:
            break;
    }


    /*  cout<<endl;
      int x = 0;
      do{cout<<GRN "Գրեք տողը:"; cin>>x;}while((x < 1) || (x > 9) );

      int y = 0;
      do{cout<<GRN "Գրեք սյունը:"; cin>>y;}while((y < 1) || (y > 9) );

      if(tableForCheck[x-1][y-1]){
          cout<< RED "Դիրքը զբաղված է, փորձեք այլ դիրք"<<endl;
      }else {
          int value = 0;
          do {
              cout << "Գրեք ներմուծվող արժեքը:";
              cin >> value;
              cout<<endl;
          }
          while ((value < 1) || (value > 9));

          table[x - 1][y - 1] = value;
      }*/

}

bool isFull(int arr[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((arr[i][j])==0){
                return false;
            }
        }
    }

    return true;

}

bool win(int arr[n][n]){

    if(isFull(arr)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!(checkRow(table[i][j], i ) && checkCol(table[i][j], j))){
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

////////////////////////

////////Easy Mode///////

bool EasyCheckRow(int v, int r){
    if(count(easyTable[r], easyTable[r] + n, v)==0){
        return true;
    }
    return false;
}

bool EasyCheckCol(int v, int c){
    int count = 0;
    for(int j = 0; j < n; j++){
        if(easyTable[j][c] == v){count++;}
    }

    if(count == 0){
        return true;
    }

    return false;
}

bool EasyCheckTab(int v ,int c, int r){

}

bool winEasyMode(int arr[n][n]){
    return isFull(arr);
}

void easyLogic(){
    cout<<endl;
    int x = 0;
    do{cout<<GRN "Գրեք տողը:"; cin>>x;}while((x < 1) || (x > 9) );

    int y = 0;
    do{cout<<GRN "Գրեք սյունը:"; cin>>y;}while((y < 1) || (y > 9) );

    if(tableForCheck[x-1][y-1]){
        cout<< RED "Դիրքը զբաղված է, փորձեք այլ դիրք"<<endl;
    }else{
        int value = 0;
        do {
            cout << "Գրեք ներմուծվող արժեքը:";
            cin >> value;
            cout<<endl;
        }
        while ((value < 1) || (value > 9));

        if(( EasyCheckCol(value, y) && EasyCheckRow(value, x))){
            easyTable[x - 1][y - 1] = value;
            return;
        }

        cout<<RED "Դուք չեք կարող դնել " << defPoint << value <<RED  " արժեքը " << defPoint " ( " << x << " : " << y << " ) " << RED " դիրքում։ \n";


    }
}


//////////

int main(){

    SelectMode();

       if(gameMode == 1){
           //EasyMode
           while(!winEasyMode(easyTable) && !(gameOver)){
               cout << "\033[2J\033[1;1H";
               Draw(easyTable);
               easyLogic();
           }


       }else if(gameMode == 2){
           //HardMode
           while(!win(table) && !(gameOver)) {
               cout << "\033[2J\033[1;1H";
               Draw(table);
               Input();
               Logic();
               cout<<endl;

           }

       }



    return 0;

}

