#include <iostream>
#include <bits/stdc++.h>


////Colors////
#define RST  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define MAG  "\x1B[35m"
//////////////

using namespace std;

/////Variables////
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

int table[n][n] = {{0, 4, 5, 0, 0, 0, 7, 8, 0},
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

///////Global//////////

void SelectMode(){
    cout << "\033[2J\033[1;1H";

    cout<<GRN "Select game mode..."<<endl;
    cout<<RED "[1]" << GRN "Easy Mode" <<endl;
    cout<<RED "[2]" << GRN "Hard Mode"<<endl;
    cout<< RST "Select: ";
    do{ cout<< RST "Select: "; cin>>gameMode;}while(!((gameMode == 1) || (gameMode == 2)));

}

void Welcome(){
    cout << "\033[2J\033[1;1H";
    int x = 0;
    cout<<"             Welcome         "<<endl<<endl;
    cout<< GRN "Սեղմեք "<< RED "[1]" << GRN ", այնուհետև " << RED "[Enter]" << GRN ", ոռրպեսզի խաղը սկսվի..."<<endl;
    do{cin>>x;}while(x != 1);

    if(x == 1){SelectMode();}
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
    cout<< "  ";
    for(int i = 0; i <4*n; i ++){

        cout<< RED "=";
    }
    cout<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if ((j == 0) || (j == 3) || (j == 6)) {

                cout << RED " | ";
            } else {

                cout << MAG " | ";
            }
            if (arr[i][j] == 0) {
                cout << MAG "_";

            } else if (arr[i][j] != 0 && tableForCheck[i][j] != 0) {
                cout << MAG << arr[i][j];
            } else {
                cout << GRN << arr[i][j];

            }


        }


        cout<< RED " | ";
        cout<<endl;



    }
    cout<< " ";
    for(int i = 0; i <4*n; i ++){
        cout<< RED "=";
    }
    cout<<endl;

}

void Logic(){

    cout<<endl;
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

        cout<<RED "Դուք չեք կարող դնել " << RST << value <<RED  " արժեքը " << RST " ( " << x << " : " << y << " ) " << RED " դիրքում։ \n";


    }
}


//////////

int main(){

    Welcome();

    if(gameMode == 1){
        //EasyMode
        while(!winEasyMode(easyTable)){
            cout << "\033[2J\033[1;1H";
            Draw(easyTable);
            easyLogic();
        }

        Draw(easyTable);
        cout<<"You WIN";

    }else if(gameMode == 2){
        //HardMode
        while(!win(table)) {
            cout << "\033[2J\033[1;1H";
            Draw(table);
            Logic();
        }

        Draw(table);
        cout<<"You WIN";
    }



    return 0;

}

