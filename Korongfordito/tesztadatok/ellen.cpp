#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void switch_lamp(vector<vector<int>>& t, int i, int j) {
    int n = t.size();
    t[i][j] = 1 - t[i][j];
    for (auto d : dir) {
        int ii = i + d.first;
        int jj = j + d.second;
        if (0 <= ii && ii < n && 0 <= jj && jj < n) {
            t[ii][jj] = 1 - t[ii][jj];
        }
    }
}

bool check(string Tes, ifstream& TinF, ifstream& ToutF, ifstream& CoutF) {
    // read input
    int n;
    TinF >> n;
    vector<vector<int>> t(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string row;
        TinF >> row;
        for (int j = 0; j < n; j++) {
            t[i][j] = (row[j] - '0');
        }
    }

    // read contestant and jury solution
    string answer_line, correct_line;
    getline(ToutF, correct_line);
    getline(CoutF, answer_line);
    if (CoutF.fail()) {
        cout << Tes + ";1;0;Hiba, output formátum hiba!" << endl;
        return false;
    }
    int opt;
    stringstream correct_ss(correct_line);
    correct_ss >> opt;

    stringstream ss(answer_line);
    int ans;
    ss >> ans;
    if (ss.fail()) {
        cout << Tes + ";1;0;Hiba, output formátum hiba!" << endl;
        return false;
    }
    // check optimality
    if (ans != opt) {
        cout << Tes + ";1;0;Hiba, hibás kimenet!" << endl;
        return false;
    }
    if (ans == -1) return true;

    // check correctness
    for (int k = 0; k < ans; k++) {
        int i, j;
        ss >> i >> j;
        if (ss.fail() || i < 1 || i >  n || j < 1 || j > n) {
            cout << Tes + ";1;0;Hiba, output formátum hiba!" << endl;
            return false;
        }
        switch_lamp(t, i - 1, j - 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (t[i][j] == 1) {
                cout << Tes + ";1;0;Hiba, hibás kimenet!" << endl;
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    string Tes = argv[3];
    string TinFn = (string)argv[1] + "/in." + Tes;
    string ToutFn = (string)argv[1] + "/out." + Tes;
    string CoutFn = (string)argv[2] + "/out." + Tes;

    ifstream TinF(TinFn.c_str());
    ifstream ToutF(ToutFn.c_str());
    ifstream CoutF(CoutFn.c_str());

    int T;
    TinF >> T;

    for (int tt = 0; tt < T; tt++) {
        if (!check(Tes, TinF, ToutF, CoutF))
            return 0;
    }

    cout << Tes + ";1;1;Helyes" << endl;
    TinF.close();
    ToutF.close();
    CoutF.close();
    return 0;
}
