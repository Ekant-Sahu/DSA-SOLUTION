#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const long long INF = 1e18;

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

    // Distance arrays: dist[u][0] -> without coupon, dist[u][1] -> with coupon
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    dist[1][0] = 0; // Start at city 1 without using the coupon

    // Min-heap for Dijkstra's algorithm (distance, city, coupon_used)
    priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<tuple<long long, int, bool>>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [d, u, coupon_used] = pq.top();
        pq.pop();

        // If the current distance is greater than the stored distance, continue
        if (d > dist[u][coupon_used])
            continue;

        // Relax edges
        for (auto edge : graph[u])
        {
            int v = edge.to;
            long long cost = edge.cost;

            // Case 1: Without using the coupon
            if (!coupon_used && dist[u][0] + cost < dist[v][0])
            {
                dist[v][0] = dist[u][0] + cost;
                pq.push({dist[v][0], v, 0});
            }

            // Case 2: Using the coupon
            if (!coupon_used && dist[u][0] + cost / 2 < dist[v][1])
            {
                dist[v][1] = dist[u][0] + cost / 2;
                pq.push({dist[v][1], v, 1});
            }

            // Case 3: After using the coupon
            if (coupon_used && dist[u][1] + cost < dist[v][1])
            {
                dist[v][1] = dist[u][1] + cost;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    // The answer is the minimum cost to reach city n, either using the coupon or not
    cout << min(dist[n][0], dist[n][1]) << endl;

    return 0;
}
