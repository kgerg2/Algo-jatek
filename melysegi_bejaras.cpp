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