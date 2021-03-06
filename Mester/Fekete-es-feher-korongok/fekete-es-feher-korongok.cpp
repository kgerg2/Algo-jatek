#include <iostream>

using namespace std;

string szoveg;
int ert[1000][1000];

void kiszamol(int k, int v){
    string j = szoveg.substr(k, v-k), b = szoveg.substr(k+1, v-k);
    int egyes=0, i=0;
    if(ert[k][v-1] == -1) kiszamol(k, v-1);
    if(ert[k+1][v] == -1) kiszamol(k+1, v);
    for(int i=k; i<=v; i++){
        if(szoveg[i] == '1') egyes++;
    }
    ert[k][v] = egyes - (ert[k][v-1] > ert[k+1][v] ? ert[k+1][v] : ert[k][v-1]);
}

int main(){
    int i, j, hossz;
    cin >> hossz;
    char s[hossz+1];
    
    i = 0;
    cin.ignore();
    while(i < hossz && cin >> s[i]){
        cin.ignore();
        i++;
    }
    int ujhossz = 0, extra = 0;

    for(i=0; i<hossz; i++){
        if(i < hossz-1 && s[i] == '1' && s[i+1] == '1'){
            i++;
            extra++;
        } else{
            s[ujhossz] = s[i];
            ujhossz++;
        }
    }
    s[ujhossz] = '\0';

    hossz = ujhossz;
    ujhossz = 0;
    for(i=0; i<hossz; i++){
        if(i < hossz-2 && s[i] == '0' && s[i+1] == '0' && s[i+2] == '0'){
            i++;
        } else{
            s[ujhossz] = s[i];
            ujhossz++;
        }
    }
    s[ujhossz] = '\0';

    szoveg = s;
    for(i=0; i<ujhossz; i++){
        ert[i][i] = 0;
        for(j=i+1; j<ujhossz; j++){
            ert[i][j] = -1;
        }
    }

    kiszamol(0, ujhossz-1);

    cout << ert[0][ujhossz-1] + extra;

    return 0;
}