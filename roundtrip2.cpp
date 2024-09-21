#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited, parent;
int cycle_start = -1, cycle_end;

bool dfs(int v)
{
    visited[v] = 1; // Mark current node as visited
    for (int u : graph[v])
    {
        if (visited[u] == 0)
        { // Node u is unvisited
            parent[u] = v;
            if (dfs(u))
                return true;
        }
        else if (visited[u] == 1)
        { // Node u is part of the current DFS path, indicating a cycle
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }
    visited[v] = 2; // Mark current node as fully explored
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Initialize the graph
    graph.resize(n + 1);
    visited.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    // Input the flights (directed edges)
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    // Try to find a cycle starting from any unvisited node
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i))
                break; // If a cycle is found, stop the search
        }
    }

    if (cycle_start == -1)
    {
        // No cycle found
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        // Reconstruct the cycle
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
        {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        // Output the cycle
        cout << cycle.size() << endl;
        for (int v : cycle)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
