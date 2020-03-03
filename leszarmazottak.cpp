#include <vector>

using namespace std;

vector<vector<int>> children;

int subtree(int p)
{
    int cnt = 1;
    for (int c : children[p])
    {
        cnt += subtree(c);
    }
    return cnt;
}