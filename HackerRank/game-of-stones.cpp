#include <bits/stdc++.h>

using namespace std;
int firstWins[101];

bool winner(int n){
    if(firstWins[n] == -1){
        firstWins[n] = !winner(n-2) || !winner(n-3) || !winner(n-5);
    }
    return firstWins[n];
}

// Complete the gameOfStones function below.
string gameOfStones(int n) {
    if(winner(n)){
        return "First";
    } else {
        return "Second";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int i;
    for(i=0;i<=100;i++){
        if(i < 2){
            firstWins[i] = 0;
        } else if(i < 7){
            firstWins[i] = 1;
        } else{
            firstWins[i] = -1;
        }
    }
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}