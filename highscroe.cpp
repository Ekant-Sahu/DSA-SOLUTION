#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

const long long INF = 1e18; // A large value representing infinity

int main()
{
    int n, m;
    cin >> n >> m;

    // Store all edges as tuples of (start, end, weight)
    vector<tuple<int, int, long long>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
    }

    // Distance array to track maximum score, initialize with -INF
    vector<long long> dist(n + 1, -INF);
    dist[1] = 0; // Start from room 1 with a score of 0

    // Bellman-Ford Algorithm: Relax edges up to n-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto [a, b, x] : edges)
        {
            if (dist[a] != -INF && dist[a] + x > dist[b])
            {
                dist[b] = dist[a] + x;
            }
        }
    }

    // Detect positive weight cycles
    vector<bool> in_positive_cycle(n + 1, false);
    queue<int> cycle_queue;

    for (auto [a, b, x] : edges)
    {
        if (dist[a] != -INF && dist[a] + x > dist[b])
        {
            in_positive_cycle[b] = true;
            cycle_queue.push(b); // Start checking nodes involved in cycles
        }
    }

    // Use BFS/DFS to propagate positive cycle influence
    while (!cycle_queue.empty())
    {
        int node = cycle_queue.front();
        cycle_queue.pop();

        for (auto [a, b, x] : edges)
        {
            if (in_positive_cycle[a] && !in_positive_cycle[b])
            {
                in_positive_cycle[b] = true;
                cycle_queue.push(b);
            }
        }
    }

    // If room `n` is in a positive weight cycle, print -1
    if (in_positive_cycle[n])
    {
        cout << -1 << endl;
    }
    else
    {
        // Otherwise, print the maximum score achievable at room n
        cout << dist[n] << endl;
    }

    return 0;
}
