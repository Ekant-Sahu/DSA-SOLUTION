#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Flight
{
    int to;
    long long cost;
};

// A custom comparator to use priority_queue as a min-heap
struct State
{
    long long cost;
    int city;

    // Sort by cost, so we can pop the smallest cost first
    bool operator<(const State &other) const
    {
        return cost > other.cost; // Reverse to create a min-heap
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    // Adjacency list representation of the graph
    vector<vector<Flight>> graph(n + 1);

    // Reading the input
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // To store the k shortest paths to each city
    vector<vector<long long>> dist(n + 1);

    // Priority queue to process the cities in the order of the cheapest current cost
    priority_queue<State> pq;

    // Start from city 1 with cost 0
    pq.push({0, 1});

    // Process until we find the k shortest paths to city n
    while (!pq.empty())
    {
        auto [current_cost, u] = pq.top();
        pq.pop();

        // If we already have found k paths to this city, skip
        if (dist[u].size() >= k)
            continue;

        // Record this path cost to city u
        dist[u].push_back(current_cost);

        // Expand to all neighboring cities
        for (auto flight : graph[u])
        {
            int v = flight.to;
            long long new_cost = current_cost + flight.cost;

            // Only push if we haven't found k paths to city v yet
            if (dist[v].size() < k)
            {
                pq.push({new_cost, v});
            }
        }
    }

    // Output the k shortest paths to city n
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
    cout << endl;

    return 0;
}
