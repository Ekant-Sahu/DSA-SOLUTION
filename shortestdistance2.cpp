#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18; // A large number to represent infinity

// Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
vector<vector<long long>> floyd_warshall(int n, vector<vector<long long>> &dist)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    // Initialize distance matrix
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Set the distance from a city to itself as 0
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    // Read the roads and set the initial distances
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // Use the minimum distance in case of multiple roads
        dist[b][a] = min(dist[b][a], c); // Because the roads are two-way
    }

    // Run the Floyd-Warshall algorithm to compute shortest paths
    dist = floyd_warshall(n, dist);

    // Process the queries
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
        {
            cout << -1 << endl; // No route between city a and city b
        }
        else
        {
            cout << dist[a][b] << endl; // Print the shortest distance
        }
    }

    return 0;
}
