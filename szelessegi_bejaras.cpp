#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int v : G[current])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}