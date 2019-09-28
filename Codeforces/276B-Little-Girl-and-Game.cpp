#include <iostream>

using namespace std;

int main(){
    string names[2] = {"First", "Second"};
    char c;
    bool even[26], result = true, odd = false; // 97 - 122
    int i;
    for(i=0; i<26; i++){
        even[i] = true;
    }
    while(cin >> c){
        i = int(c)-97;
        if(i >= 0 && i < 26){
            even[int(c)-97] = !even[int(c)-97];
        }
    }
    for(i=0; i<26; i++){
        if(!even[i]){
            result = !result;
            odd = true;
        }
    }
    cout << names[result && odd];
    return 0;
}