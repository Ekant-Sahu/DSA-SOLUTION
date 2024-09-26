#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 200001;

vector<int> teleporter(MAX_N);
vector<int> dist(MAX_N);
vector<bool> visited(MAX_N);

int bfs(int start, int target, int n)
{
    queue<int> q;
    fill(dist.begin(), dist.begin() + n + 1, -1);          // Reset distance array
    fill(visited.begin(), visited.begin() + n + 1, false); // Reset visited array

    q.push(start);
    dist[start] = 0;
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Get the destination from the teleporter at planet u
        int v = teleporter[u];

        if (!visited[v])
        {
            visited[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }

        // If we reach the target planet
        if (v == target)
        {
            return dist[v];
        }
    }

    return -1; // If we can't reach the target
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    // Read the teleporter destinations
    for (int i = 1; i <= n; i++)
    {
        cin >> teleporter[i];
    }

    // Process each query
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << '\n'; // If we are already at the destination
        }
        else
        {
            cout << bfs(a, b, n) << '\n'; // Use BFS to find the minimum teleportations
        }
    }

    return 0;
}
