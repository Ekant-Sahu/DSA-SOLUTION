#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N], adj_rev[MAX_N]; // Original and reversed graphs
vector<bool> visited(MAX_N);
stack<int> finish_stack;    // Stack to store the finish order of nodes
vector<int> kingdom(MAX_N); // Stores the kingdom label for each planet
int kingdom_count = 0;

// Perform DFS to fill the finish_stack (on the original graph)
void dfs1(int node)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs1(neighbor);
        }
    }
    finish_stack.push(node); // Push the node onto the stack after visiting all its neighbors
}

// Perform DFS on the reversed graph to find SCCs
void dfs2(int node, int label)
{
    visited[node] = true;
    kingdom[node] = label; // Assign the current kingdom label to this node
    for (int neighbor : adj_rev[node])
    {
        if (!visited[neighbor])
        {
            dfs2(neighbor, label);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Read the teleporters and construct both the original and reversed graphs
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);     // Original graph (a -> b)
        adj_rev[b].push_back(a); // Reversed graph (b -> a)
    }

    // First DFS to calculate the finishing order (on the original graph)
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    // Second DFS to find SCCs (on the reversed graph)
    visited.assign(n + 1, false);
    while (!finish_stack.empty())
    {
        int node = finish_stack.top();
        finish_stack.pop();
        if (!visited[node])
        {
            kingdom_count++;
            dfs2(node, kingdom_count); // Label this SCC with a new kingdom number
        }
    }

    // Output the number of kingdoms and the kingdom label for each planet
    cout << kingdom_count << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << kingdom[i] << " ";
    }
    cout << "\n";

    return 0;
}
