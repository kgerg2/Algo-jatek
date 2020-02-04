#include <iostream>
// #include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

map<set<int>, bool> nyerok;

set<int> operator^=(set<int> &A, int x)
{
    if (A.find(x) == A.end())
    {
        A.insert(x);
    }
    else
    {
        A.erase(x);
    }
    return A;
}

void kiszamol(set<int> lista)
{
    for (auto h : lista)
    {
        for (int j = 0; j < h; j++)
        {
            for (int vagh = 1; vagh <= 2; vagh++)
            {
                if (j == h - 1 && vagh == 2)
                    continue;
                set<int> ujlista(lista);
                ujlista.erase(h);
                if (j == 0 || j == h - 1)
                {
                    ujlista ^= h - vagh;
                }
                else if (h > vagh)
                {
                    ujlista ^= j;
                    ujlista ^= h - vagh - j;
                }
                ujlista.erase(0);

                if (nyerok.find(ujlista) == nyerok.end())
                    kiszamol(ujlista);
                
                if (nyerok[ujlista])
                {
                    nyerok[lista] = false;
                    return;
                }
            }
        }
    }
    nyerok[lista] = true;
}

bool bemenetre_megold(int *be, int hossz){
    vector <int> lista;
    lista.push_back(0);
    for (int i = 0; i<hossz; i++){
        if (be[i])
            lista.push_back(0);
        else
            lista[lista.size()-1] += 1;
    }
    set <int> halmaz;
    for (auto x : lista)
        if (count(lista.begin(), lista.end(), x) % 2)
            halmaz.insert(x);
    
    halmaz.erase(0);

    if (nyerok.find(halmaz) == nyerok.end())
        kiszamol(halmaz);

    return nyerok[halmaz];
}

int main()
{
    int adatdb, hossz, korongok[100];
    bool kesz;
    // freopen(".\\Korongfordito\\tesztadatok\\in.20", "r", stdin);
    // freopen(".\\Korongfordito\\tesztadatok\\out.20", "w", stdout);

    cin >> adatdb;
    for (int i = 0; i < adatdb; i++)
    {
        cin >> hossz;
        int eltol = 0;
        do
        {
            cin >> korongok[eltol];
            eltol++;
        } while (korongok[eltol-1] == 0 && eltol < hossz);
        if (korongok[eltol-1] == 0)
        {
            if (hossz <= 2)
                cout << "IGEN 1 " << hossz << "\n";
            else
                cout << "NEM\n";
            continue;
        }
        eltol--;
        korongok[0] = 1;
        for (int j = 1; j < hossz - eltol; j++)
        {
            cin >> korongok[j];
        }
        for (int j = hossz - eltol; j < hossz; j++)
        {
            korongok[j] = 0;
        }
        kesz = false;
        for (int k = 0; k < hossz && !kesz; k++)
        {
            int j = (k - eltol + hossz) % hossz;
            if (!korongok[j])
            {
                korongok[j] = 1;
                if (bemenetre_megold(korongok, hossz))
                {
                    cout << "IGEN " << k + 1 << " 1\n";
                    kesz = true;
                }
                if (j < hossz-1 && !korongok[j+1])
                {
                    korongok[j+1] = 1;
                    if (bemenetre_megold(korongok, hossz))
                    {
                        cout << "IGEN " << k + 1 << " 2\n";
                        kesz = true;
                    }
                    korongok[j+1] = 0;
                }
                korongok[j] = 0;
            }
        }
        if (!kesz)
        {
            cout << "NEM\n";
        }
        
    }
    return 0;
}