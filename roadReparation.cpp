#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100001;
const long long INF = 1e18; // Large value representing infinity

vector<pair<int, int>> adj[MAX_N]; // Adjacency list to store {neighbor, cost}

// Prim's Algorithm to find the Minimum Spanning Tree
long long prim(int n)
{
    vector<bool> visited(n + 1, false);                                                 // To check if a city is already included in the MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap: {cost, city}

    pq.push({0, 1}); // Start from city 1 with a cost of 0
    long long total_cost = 0;
    int edges_used = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int city = pq.top().second;
        pq.pop();

        // If this city is already part of the MST, skip it
        if (visited[city])
            continue;

        // Mark the city as visited and add its cost
        visited[city] = true;
        total_cost += cost;
        edges_used++;

        // Add all the neighbors of the current city to the priority queue
        for (auto edge : adj[city])
        {
            int next_city = edge.first;
            int next_cost = edge.second;
            if (!visited[next_city])
            {
                pq.push({next_cost, next_city});
            }
        }
    }

    // Check if all cities are connected (i.e., we used exactly n cities)
    if (edges_used == n)
    {
        return total_cost; // Return the total cost of the MST
    }
    else
    {
        return -1; // Return -1 if it's impossible to connect all cities
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Read the roads and build the adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    // Run Prim's algorithm to calculate the minimum reparation cost
    long long result = prim(n);

    if (result == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << result << '\n';
    }

    return 0;
}
