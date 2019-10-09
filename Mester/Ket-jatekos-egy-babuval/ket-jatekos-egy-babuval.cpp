#include ".\Cpp\gep.h"
#include ".\Cpp\gep.cpp"

struct cella
{
    int ertek = -1;
    int szam = 0;
};

cella m[1000][1000];
int meret;

void ertekszamol(int x, int y){
    if(x + y >= 2*meret-3){
        m[x][y].ertek = m[x][y].szam;
        cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    }
    if(x >= meret-1){
        if(m[x][y+2].ertek == -1) ertekszamol(x, y+2);
        m[x][y].ertek = m[x][y+2].ertek + m[x][y].szam;
        cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    }
    if(y >= meret-1){
        if(m[x+2][y].ertek == -1) ertekszamol(x+2, y);
        m[x][y].ertek = m[x+2][y].ertek + m[x][y].szam;
        cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
        return;
    }
    int l, j;
    if(m[x+1][y+1].ertek == -1) ertekszamol(x+1, y+1);
    if(x == meret-2){
        j = m[x+1][y+1].ertek;
    } else{
        if(m[x+2][y].ertek == -1) ertekszamol(x+2, y);
        j = m[x+2][y].ertek > m[x+1][y+1].ertek ? m[x+1][y+1].ertek : m[x+2][y].ertek;
    }
    if(y == meret-2){
        l = m[x+1][y+1].ertek;
    } else{
        if(m[x][y+2].ertek == -1) ertekszamol(x, y+2);
        l = m[x][y+2].ertek > m[x+1][y+1].ertek ? m[x+1][y+1].ertek : m[x][y+2].ertek;
    }
    m[x][y].ertek = m[x][y].szam + (l > j ? l : j);
    cout << "[" << x << ", " << y << "] - " <<  m[x][y].ertek << endl;
}

int main(){
    int i, j;
    meret = Kezd();
    for(i=0; i<meret; i++){
        for(j=i%2; j<meret; j+=2){
            m[i][j].szam = Mezo(i, j);
        }
    }
    ertekszamol(0, 0);
    for(i=0; i<meret; i++){
        for(j=0; j<meret; j++){
            cout << "(" << m[i][j].szam << "," << m[i][j].ertek << ") ";
        }
        cout << endl;
    }
    return 0;
}