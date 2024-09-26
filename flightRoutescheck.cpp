#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100001;
vector<int> adj[MAX_N], adj_rev[MAX_N]; // adj: original graph, adj_rev: reversed graph
vector<bool> visited(MAX_N);

// Perform DFS in the original or reversed graph
void dfs(int node, const vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Read the flights and construct the original and reversed graphs
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);     // Original graph (a -> b)
        adj_rev[b].push_back(a); // Reversed graph (b -> a)
    }

    // First DFS in the original graph starting from city 1
    visited.assign(n + 1, false);
    dfs(1, adj, visited);

    // Check if all cities are reachable from city 1 in the original graph
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "NO\n";
            cout << 1 << " " << i << "\n"; // 1 cannot reach i
            return 0;
        }
    }

    // Second DFS in the reversed graph starting from city 1
    visited.assign(n + 1, false);
    dfs(1, adj_rev, visited);

    // Check if all cities are reachable from city 1 in the reversed graph
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "NO\n";
            cout << i << " " << 1 << "\n"; // i cannot reach 1
            return 0;
        }
    }

    // If both DFS traversals visited all cities, the graph is strongly connected
    cout << "YES\n";

    return 0;
}
