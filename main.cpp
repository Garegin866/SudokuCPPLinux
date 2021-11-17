#include <iostream>
#include <bits/stdc++.h>
#include "conio.h"
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

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
enum eDir {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9, STOP, LEFT, RIGHT, UP, DOWN };
eDir dir;
int dirX , dirY ;
bool gameOver = false;
bool gameWin = false;
int gameMode = 0;
const int n = 9;
int tableForCheck[n][n];
int table[n][n];
int easyTable[n][n];
int tableNewCol[n][n];
int tableNewRow[n][n];
int tableNew9x3[n][n];
int tableNew3x9[n][n];
int tableForGen[n][n] = {
                          {1, 2, 3, 4, 5, 6, 7, 8, 9},
                          {4, 5, 6, 7, 8, 9, 1, 2, 3},
                          {7, 8, 9, 1, 2, 3, 4, 5, 6},
                          {2, 3, 1, 5, 6, 4, 8, 9, 7},
                          {5, 6, 4, 8, 9, 7, 2, 3, 1},
                          {8, 9, 7, 2, 3, 1, 5, 6, 4},
                          {3, 1, 2, 6, 4, 5, 9, 7, 8},
                          {6, 4, 5, 9, 7, 8, 3, 1, 2},
                          {9, 7, 8, 3, 1, 2, 6, 4, 5}
};



//////////////////


//////Function declarations//////
////Random table/////


void RandomTable(int mode) {


    //change table by columns

    int arrCol[n];
    srand ( time(NULL) );
    for(int i = 0; i < n;i+=3){
        int n1=i,n2 =i,n3=i;
        n1 = (rand() % 3);
        arrCol[i] = n1+i;
        do {
            n2 = rand() % 3;
        } while (n2 == n1);
        arrCol[i+1] = n2+i;

        do {
            n3 = rand() % 3;
        } while ((n3 == n1) || (n3 == n2));
        arrCol[i+2] = n3+i;
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0; j <n; j++){
            tableNewCol[i][j] = tableForGen[i][arrCol[j]];
        }
    }

    //change table by rows

    int arrRow[n];
    srand ( time(NULL) );
    for(int i = 0; i < n;i+=3){
        int n1=i,n2 =i,n3=i;
        n1 = (rand() % 3);
        arrRow[i] = n1+i;
        do {
            n2 = rand() % 3;
        } while (n2 == n1);
        arrRow[i+1] = n2+i;

        do {
            n3 = rand() % 3;
        } while ((n3 == n1) || (n3 == n2));
        arrRow[i+2] = n3+i;
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0; j <n; j++){
            tableNewRow[i][j] = tableNewCol[arrRow[i]][j];
        }
    }

    //change table by 9x3

    int arr9x3[3];
    srand ( time(NULL) );
    int n1=0,n2 =0,n3=0;
    n1 =(rand() % 3);
    arr9x3[0] = n1;
    do {
        n2 =( rand() % 3);
    } while (n2 == n1);
    arr9x3[1] = n2;
    do {
        n3 = (rand() % 3);
    } while ((n3 == n1) || (n3 == n2));
    arr9x3[2] = n3;
    for(int i = 0; i <3; i++){

        for(int j = 0; j < n; j++){
            tableNew9x3[(i*3)][j] = tableNewRow[arr9x3[i]*3][j];
            tableNew9x3[(i*3)+1][j] = tableNewRow[(arr9x3[i]*3)+1][j];
            tableNew9x3[(i*3)+2][j] = tableNewRow[(arr9x3[i]*3)+2][j];
        }
    }

    //change table by 3x9

    int arr3x9[3];

    srand ( time(NULL) );
    int m1=0,m2 =0,m3=0;
    m1 =(rand() % 3);
    arr3x9[0] = m1;
    do {
        m2 =( rand() % 3);
    } while (m2 == m1);
    arr3x9[1] = m2;
    do {
        m3 = (rand() % 3);
    } while ((m3 == m1) || (m3 == m2));
    arr3x9[2] = m3;
    for(int i = 0; i <n; i++){

        for(int j = 0; j < 3; j++){
            tableNew3x9[i][j*3] = tableNew9x3[i][(arr3x9[j]*3)];
            tableNew3x9[i][(j*3)+1] = tableNew9x3[i][(arr3x9[j]*3)+1];
            tableNew3x9[i][(j*3)+2] = tableNew9x3[i][(arr3x9[j]*3)+2];
        }
    }

    if(mode == 1){
        //easyTable
        srand ( time(NULL) );

        int val =30 + (rand() % 45);
        val = 81 - val;

        int rand_row=0;
        int rand_col = 0;

        for(int i = 0; i < val; i++){
            do {
                rand_row = rand() % 9;
                rand_col = rand() % 9;
            }while(tableNew3x9[rand_row][rand_col] == 0);

            tableNew3x9[rand_row][rand_col]=0;

        }

        //copying table

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                easyTable[i][j] = tableNew3x9[i][j];
            }
        }


    }else{
        //hard mode

        srand ( time(NULL) );

        int val =20 + (rand() % 27);
        val = 81 - val;

        int rand_row=0;
        int rand_col = 0;

        for(int i = 0; i < val; i++){
            do {
                rand_row = rand() % 9;
                rand_col = rand() % 9;
            }while(tableNew3x9[rand_row][rand_col] == 0);

            tableNew3x9[rand_row][rand_col]=0;

        }

        //copying table

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                table[i][j] = tableNew3x9[i][j];
            }
        }

    }

}

//////////Global//////////

void Setup(int var){
    RandomTable(var);

    if(var == 1){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n ; j++ ){
                tableForCheck[i][j] = easyTable[i][j];
            }
        }
    }else if(var == 2){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n ; j++ ){
                tableForCheck[i][j] = table[i][j];
            }
        }
    }

}

void Input() {

    if (_kbhit()) {
        switch (_getche())
        {
            case 68:
            case 'a':
                dir = LEFT;
                break;
            case 65:
            case 'w':
                dir = UP;
                break;
            case 66:
            case 's':
                dir = DOWN;
                break;
            case 67:
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
            case '0':
                dir = n0;
                break;
            default:
                break;
        }
    }else{
        dir = STOP;
    }
}

void SelectMode(){
    cout << "\033[2J\033[1;1H";
    cout<< BOLD;

    cout<<GRN "Select game mode..."<<endl;
    cout<<SYSTEXT "[1]" << "Easy Mode" <<endl;
    cout<<RED "[2]" << "Hard Mode"<<endl<<endl;
    do{ cout<< GRN "Select: "; cin>>gameMode;}while(!((gameMode == 1) || (gameMode == 2)));

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
    for(auto & j : table){
        if(j[c] == v){count++;}
    }

    if(count == 1){
        return true;
    }
    return false;
}

void Draw(int arr[n][n]){
    cout << "\033[2J\033[1;1H";

    this_thread::sleep_for(chrono::milliseconds(8));
    cout<< "  ";
    cout<<endl;

    for(int i = 0; i < n; i++){
        if(i == 0 || i == 3 || i == 6 ){
            cout<< BORDER " ###########################################";
            cout<<endl;
        }else {
            cout << BORDER " #"
                 << innerBORDER "⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺ " BORDER "#" innerBORDER "⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺ "  BORDER "#" innerBORDER "⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺⸺  "
                 << BORDER "#";

            cout << endl;
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
                    cout<<ACTIVE BOLD << "▪";
                }else {
                    cout << defPoint BOLD "▫";
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
            if(dirX > 0){
                dirX--;
                break;
            }else{
                break;
            }
        case RIGHT:
            if(dirX <8){
                dirX++;
                break;
            }else{
                break;
            }
        case UP:
            if(dirY > 0){
                dirY--;
                break;
            }else{
                break;
            }
        case DOWN:
            if(dirY <8){
                dirY++;
                break;
            }else{
                break;
            }
        case n1:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 1;
            }
            break;
        case n2:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 2;
            }
            break;
        case n3:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 3;
            }
            break;
        case n4:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 4;
            }
            break;
        case n5:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 5;
            }
            break;
        case n6:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 6;
            }
            break;
        case n7:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 7;
            }
            break;
        case n8:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 8;
            }
            break;
        case n9:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 9;
            }
            break;
        case n0:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                table[dirY][dirX] = 0;
            }
            break;

        case STOP:
            break;
    }

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
                if(!(checkRow(arr[i][j], i ) && checkCol(arr[i][j], j))){
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
    for(auto & j : easyTable){
        if(j[c] == v){count++;}
    }

    if(count == 0){
        return true;
    }

    return false;
}

bool EasyCheckTab(int v ,int c, int r){
    if(((c >= 0)&&(c<= 2))&&((r >= 0)&& (r<= 2))){

        for(int i = 0; i <= 2; i++){
            for(int j = 0; j <= 2; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    }else if(((c >= 3)&&(c<= 5))&&((r >= 0)&& (r<= 2))){

        for(int i = 0; i <= 2; i++){
            for(int j = 3; j <= 5; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    } else if(((c >= 6)&&(c<= 8))&&((r >= 0)&& (r<= 2))){

        for(int i = 0; i <= 2; i++){
            for(int j = 6; j <= 8; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    }else if(((c >= 0)&&(c<= 2))&&((r >= 3)&& (r<= 5))){

        for(int i = 3; i <= 5; i++){
            for(int j = 0; j <= 2; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    }else if(((c >= 3)&&(c<= 5))&&((r >= 3)&& (r<= 5))){

        for(int i = 3; i <= 5; i++){
            for(int j = 3; j <= 5; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    } else if(((c >= 6)&&(c<= 8))&&((r >= 3)&& (r<= 5))){

        for(int i = 3; i <= 5; i++){
            for(int j = 6; j <= 8; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    }else if(((c >= 0)&&(c<= 2))&&((r >= 6)&& (r<= 8))){

        for(int i = 6; i <= 8; i++){
            for(int j = 0; j <= 2; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    }else if(((c >= 3)&&(c<= 5))&&((r >= 6)&& (r<= 8))){

        for(int i = 6; i <= 8; i++){
            for(int j = 3; j <= 5; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    } else if(((c >= 6)&&(c<= 8))&&((r >= 6)&& (r<= 8))){

        for(int i = 6; i <= 8; i++){
            for(int j = 6; j <= 8; j++){
                if(easyTable[i][j] == v){
                    return false;
                }
            }
        }
        return true;

    }
}

bool winEasyMode(int arr[n][n]){
    return isFull(arr);
}

void easyLogic(){
    cout<<endl;
    int x = 0;
    switch (dir) {
        case LEFT:
            if(dirX > 0){
                dirX--;
                break;
            }else{
                break;
            }
        case RIGHT:
            if(dirX <8){
                dirX++;
                break;
            }else{
                break;
            }
        case UP:
            if(dirY > 0){
                dirY--;
                break;
            }else{
                break;
            }
        case DOWN:
            if(dirY <8){
                dirY++;
                break;
            }else{
                break;
            }
        case n1:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(1, dirX) && EasyCheckRow(1 , dirY) && EasyCheckTab(1, dirX, dirY)){
                easyTable[dirY][dirX] = 1;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n2:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(2, dirX) && EasyCheckRow(2 , dirY) && EasyCheckTab(2, dirX, dirY)){
                easyTable[dirY][dirX] = 2;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n3:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(3, dirX) && EasyCheckRow(3, dirY) && EasyCheckTab(3, dirX, dirY)){
                easyTable[dirY][dirX] = 3;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n4:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(4, dirX) && EasyCheckRow(4 , dirY) && EasyCheckTab(4, dirX, dirY)){
                easyTable[dirY][dirX] = 4;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n5:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(5, dirX) && EasyCheckRow(5 , dirY) && EasyCheckTab(5, dirX, dirY)){
                easyTable[dirY][dirX] = 5;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n6:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(6, dirX) && EasyCheckRow(6 , dirY) && EasyCheckTab(6, dirX, dirY)){
                easyTable[dirY][dirX] = 6;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n7:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(7, dirX) && EasyCheckRow(7 , dirY) && EasyCheckTab(7, dirX, dirY)){
                easyTable[dirY][dirX] = 7;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n8:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(8, dirX) && EasyCheckRow(8 , dirY) && EasyCheckTab(8, dirX, dirY)){
                easyTable[dirY][dirX] = 8;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n9:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else if(EasyCheckCol(9, dirX) && EasyCheckRow(9 , dirY) && EasyCheckTab(9, dirX, dirY)){
                easyTable[dirY][dirX] = 9;
                break;
            }else{
                easyTable[dirY][dirX] = 0;
                break;
            }
        case n0:
            if(tableForCheck[dirY][dirX] != 0){
                break;
            }
            else{
                easyTable[dirY][dirX] = 0;
            }
            break;

        case STOP:
            break;
    }

}


//////////

int main(){

    SelectMode();

       if(gameMode == 1){
           Setup(1);
           //EasyMode
           while(!winEasyMode(easyTable) && !(gameOver)){
               cout << "\033[2J\033[1;1H";
               Draw(easyTable);
               Input();
               easyLogic();
               cout<<endl;
           }

           if(!gameOver){
               cout<<endl;
               Draw(easyTable);
               cout<<RED "Congratulations!!!\n";
               cout<< RED "You won the game\n"<<endl;
           }


       }else if(gameMode == 2){

           Setup(2);
           //HardMode
           while(!win(table) && !(gameOver)) {
               cout << "\033[2J\033[1;1H";
               Draw(table);
               Input();
               Logic();
               cout<<endl;
               if(isFull(table)){
                   cout<<RED "Change some values in the table";
                   cout<<endl;
               }

           }

           if(!gameOver){
               cout<<endl;
               Draw(table);
               cout<<RED "Congratulations!!!\n";
               cout<< RED "You won the game\n";
           }

       }


    return 0;

}

