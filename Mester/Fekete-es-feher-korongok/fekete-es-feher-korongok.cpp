#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map <string, int> ert = {{"", 0}};

void kiszamol(string allas, int hossz){
    string j = allas.substr(0, hossz-1), b = allas.substr(1, hossz-1);
    int egyes=0, i=0;
    if(ert.find(j) == ert.end()) kiszamol(j, hossz-1);
    if(ert.find(b) == ert.end()) kiszamol(b, hossz-1);
    int jert = ert[j], bert = ert[b];
    for(int i=0; i<hossz; i++){
        if(allas[i] == '1') egyes++;
    }
    ert[allas] = egyes - (jert > bert ? bert : jert);
}

int main(){
    int i, hossz;
    cin >> hossz;
    cin.ignore();
    char s[hossz+1];
    i = 0;
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

    // cout << s << endl;
    // cout << ujhossz << endl;
    kiszamol(s, ujhossz);
    cout << ert[s] + extra;
    /* cout << "{" << endl;
    for (auto& it: ert) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "}" << endl;
    cin >> i; */
    return 0;
}