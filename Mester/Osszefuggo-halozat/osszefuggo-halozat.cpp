#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;

void DFS(int p)
{
    visited[p] = true;
    for (int v : G[p])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    G.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    vector<int> komp;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (!visited[j])
        {
            komp.push_back(j);
            DFS(j);
            i++;
        }
    }
    cout << i - 1 << endl;
    for (int j = 1; j < i; j++)
    {
        cout << komp[0] + 1 << " " << komp[j] + 1 << endl;
    }
    return 0;
}