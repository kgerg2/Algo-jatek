//#include ".\Cpp\gep.h"
//#include ".\Cpp\gep.cpp"
#include "gep.h"

struct cella
{
    int ertek = -1;
    int szam = 0;
    char irany = ' ';
};

cella m[1003][1003];
int meret;

void ertekszamol(int x, int y){
    if(x == meret-1 && y == meret-1){
        m[x][y].ertek = 0;
        m[x][y].irany = 0;
        // cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    } else if(x + y >= 2*meret-3){
        m[x][y].ertek = m[meret-1][meret-1].szam;
        m[x][y].irany = '-';
        // cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    }
    if(x >= meret-1){
        if(m[x][y+2].ertek == -1) ertekszamol(x, y+2);
        m[x][y].ertek = m[x][y+2].ertek + m[x][y+1].szam;
        m[x][y].irany = 'L';
        // cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    }
    if(y >= meret-1){
        if(m[x+2][y].ertek == -1) ertekszamol(x+2, y);
        m[x][y].ertek = m[x+2][y].ertek + m[x+1][y].szam;
        m[x][y].irany = 'J';
        // cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    }
    int l = m[x][y+1].szam, j = m[x+1][y].szam;
    if(m[x+1][y+1].ertek == -1) ertekszamol(x+1, y+1);
    if(x == meret-2){
        j += m[x+1][y+1].ertek;
    } else{
        if(m[x+2][y].ertek == -1) ertekszamol(x+2, y);
        j += m[x+2][y].ertek > m[x+1][y+1].ertek ? m[x+1][y+1].ertek : m[x+2][y].ertek;
    }
    if(y == meret-2){
        l += m[x+1][y+1].ertek;
    } else{
        if(m[x][y+2].ertek == -1) ertekszamol(x, y+2);
        l += m[x][y+2].ertek > m[x+1][y+1].ertek ? m[x+1][y+1].ertek : m[x][y+2].ertek;
    }
    m[x][y].ertek = l > j ? l : j;
    m[x][y].irany = l > j ? 'L' : 'J';
    // cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
}

int main(){
    int i, j, x, y;
    char irany;
    meret = Kezd();
    for(i=0; i<meret; i++){
        for(j=1-i%2; j<meret; j+=2){
            m[i][j].szam = Mezo(i, j);
        }
    }
    ertekszamol(0, 0);
    //ertekszamol(0, 1);
    //ertekszamol(1, 0);
    /*for(j=0; j<meret; j++){
        for(i=0; i<meret; i++){
            cout << m[i][j].irany << "(" << m[i][j].szam << "," << m[i][j].ertek << ") ";
        }
        cout << endl;
    }*/
    x = 0;
    y = 0;
    while(x + y < 2*meret-3){
        // cout << "(" << x << ", " << y << ") - " << m[x][y].irany << endl;
        Lep(m[x][y].irany);
        irany = GepLep();
        if(m[x][y].irany == 'L'){
            y++;
        } else{
            x++;
        }
        if(irany == 'L'){
            y++;
        } else{
            x++;
        }
        if(x >= meret || y >= meret) break;
    }
    return 0;
}