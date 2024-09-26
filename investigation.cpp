#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

struct Edge
{
    int to;
    long long cost;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // Distance array
    vector<long long> dist(n + 1, INF);
    vector<int> num_paths(n + 1, 0);     // Number of ways to reach each node
    vector<int> min_flights(n + 1, INF); // Minimum number of flights
    vector<int> max_flights(n + 1, 0);   // Maximum number of flights

    // Priority queue for Dijkstra
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // Start from city 1 (Syrjälä)
    dist[1] = 0;
    num_paths[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u])
            continue;

        // Explore all neighbors
        for (auto edge : graph[u])
        {
            int v = edge.to;
            long long new_dist = dist[u] + edge.cost;

            // If we find a shorter path
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                num_paths[v] = num_paths[u];         // Update the number of paths
                min_flights[v] = min_flights[u] + 1; // Update minimum flights
                max_flights[v] = max_flights[u] + 1; // Update maximum flights
                pq.push({new_dist, v});
            }
            // If we find another path with the same minimum cost
            else if (new_dist == dist[v])
            {
                num_paths[v] = (num_paths[v] + num_paths[u]) % MOD;       // Add number of ways
                min_flights[v] = min(min_flights[v], min_flights[u] + 1); // Minimize flights
                max_flights[v] = max(max_flights[v], max_flights[u] + 1); // Maximize flights
            }
        }
    }

    // Output the results for city n (Lehmälä)
    cout << dist[n] << " " << num_paths[n] << " " << min_flights[n] << " " << max_flights[n] << endl;

    return 0;
}
