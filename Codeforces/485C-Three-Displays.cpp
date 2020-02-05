#include <iostream>
#include <algorithm>

using namespace std;

bool found(pair<bool, int> *p, pair<int, int> a, pair<int, int> b, int i){
    if (p->second == -1)
    {
        if (a.first < b.first && a.second < b.second)
        {
            p->first = true;
            p->second = i;
        }
        else if (a.first > b.first && a.second > b.second)
        {
            p->first = false;
            p->second = i;
        }
    }
    else
    {
        if (p->first && a.first > b.first && a.second > b.second ||
            !p->first && a.first < b.first && a.second < b.second)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    pair<int, pair<int, int>> l[3000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i].second.second;
        l[i].second.first = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> l[i].first;
    }
    sort(l, l+n);
    pair<bool, int> t[3000];
    int minsum = 300000001;
    for (int i = 0; i < n; i++)
    {
        t[i].second = -1;
        for (int j = 0; j < i; j++)
        {
            if (found(&t[i], l[i].second, l[j].second, j))
            {
                if (l[i].first + l[j].first + l[t[i].second].first < minsum)
                {
                    minsum = l[i].first + l[j].first + l[t[i].second].first;
                }
            }
            if (found(&t[j], l[j].second, l[i].second, i))
            {
                if (l[i].first + l[j].first + l[t[j].second].first < minsum)
                {
                    minsum = l[i].first + l[j].first + l[t[j].second].first;
                }
            }
        }
    }
    if (minsum < 300000001)
    {
        cout << minsum << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
