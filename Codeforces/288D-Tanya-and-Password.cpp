
// https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
// A C++ program to print Eulerian circuit in given
// directed graph using Hierholzer algorithm
#include <bits/stdc++.h>
using namespace std;

vector<int> printCircuit(vector<vector<int>> l)
{
    // l represents the adjacency list of
    // the directed graph
    // edge_count represents the number of edges
    // emerging from a vertex
    vector<int> edge_count;

    for (int i = 0; i < l.size(); i++)
    {
        //find the count of edges to keep track
        //of unused edges
        edge_count.push_back(l[i].size());
    }

    // if (!adj.size())
    //     return; //empty graph

    // Maintain a stack to keep vertices
    stack<int> curr_path;

    // vector to store final circuit
    vector<int> circuit;

    // start from any vertex
    curr_path.push(0);
    int curr_v = 0; // Current vertex

    while (!curr_path.empty())
    {
        // If there's remaining edge
        if (edge_count[curr_v])
        {
            // Push the vertex
            curr_path.push(curr_v);

            // Find the next vertex using an edge
            int next_v = l[curr_v].back();

            // and remove that edge
            edge_count[curr_v]--;
            l[curr_v].pop_back();

            // Move to next vertex
            curr_v = next_v;
        }

        // back-track to find remaining circuit
        else
        {
            circuit.push_back(curr_v);

            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    return circuit;

    // we've got the circuit, now print it in reverse
    // for (int i = circuit.size() - 1; i >= 0; i--)
    // {
    //     cout << circuit[i];
    //     if (i)
    //         cout << " -> ";
    // }
}

int main()
{
    int n, fst, snd;
    vector<string> map;
    vector<vector<int>> l;
    vector<int> in;
    string temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        int j = 0;
        while (j < map.size() && temp.compare(1, 2, map[j]))
        {
            j++;
        }
        if (j == map.size())
        {
            map.push_back(temp.substr(1, 2));
        }
        snd = j;

        temp[2] = '\0';
        j = 0;
        while (j < map.size() && temp.compare(0, 2, map[j]))
        {
            j++;
        }
        if (j == map.size())
        {
            map.push_back(temp.substr(0, 2));
        }
        fst = j;

        while (fst >= l.size() || snd >= l.size())
        {
            l.push_back(vector<int>());
        }
        while (fst >= in.size() || snd >= in.size())
        {
            in.push_back(0);
        }
        
        l[fst].push_back(snd);
        in[snd]++;
    }
    /* for (auto &&i : l)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    } */
    
    int start = -1, end = -1;
    for (int i = 0; i < l.size(); i++)
    {
        if (l[i].size() == in[i] + 1)
        {
            if (start == -1)
            {
                start = i;
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
        else if (l[i].size() == in[i] - 1)
        {
            if (end == -1)
            {
                end = i;
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
        else if (l[i].size() != in[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    if (start != -1 && end != -1)
    {
        l[end].push_back(start);
    }
    
    // l represents the adjacency list of
    // the directed graph
    // edge_count represents the number of edges
    // emerging from a vertex
    vector<int> edge_count;

    for (int i = 0; i < l.size(); i++)
    {
        //find the count of edges to keep track
        //of unused edges
        edge_count.push_back(l[i].size());
    }

    // if (!adj.size())
    //     return; //empty graph

    // Maintain a stack to keep vertices
    stack<int> curr_path;

    // vector to store final circuit
    vector<int> circuit;

    // start from any vertex
    curr_path.push(0);
    int curr_v = 0; // Current vertex

    while (!curr_path.empty())
    {
        // If there's remaining edge
        if (edge_count[curr_v])
        {
            // Push the vertex
            curr_path.push(curr_v);

            // Find the next vertex using an edge
            int next_v = l[curr_v].back();

            // and remove that edge
            edge_count[curr_v]--;
            l[curr_v].pop_back();

            // Move to next vertex
            curr_v = next_v;
        }

        // back-track to find remaining circuit
        else
        {
            circuit.push_back(curr_v);

            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    
    if (start == -1 && end == -1)
    {
        if (circuit.size() - 1 != n)
        {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        for (int i = circuit.size()-1; i > 0; i--)
        {
            cout << map[circuit[i]][0];
        }
        cout << map[circuit[0]] << endl;
    }
    else
    {
        if (circuit.size() - 2 != n)
        {
            cout << "NO\n";
            return 0;
        }
        int i = circuit.size()-1;
        while (i > 0 && (circuit[i-1] != start || circuit[i] != end))
        {
            i--;
        }

        if (i == 0)
        {
            cout << "NO\n";
            return 0;
        }
        
        cout << "YES\n";
        for (int j = i-1; j > 0; j--)
        {
            cout << map[circuit[j]][0];
        }
        for (int j = circuit.size()-1; j > i; j--)
        {
            cout << map[circuit[j]][0];
        }
        cout << map[circuit[i]] << endl;
    }
    
    return 0;
}