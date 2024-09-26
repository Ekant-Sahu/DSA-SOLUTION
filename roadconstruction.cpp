#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100001;

int parent[MAX_N], component_size[MAX_N];
int num_components, largest_component_size;

// Find function with path compression
int find(int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

// Union function with union by size
bool unite(int u, int v)
{
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v)
    {
        // Union by size: attach the smaller tree to the larger tree
        if (component_size[root_u] < component_size[root_v])
        {
            swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        component_size[root_u] += component_size[root_v];
        component_size[root_v] = 0; // root_v is now merged into root_u
        largest_component_size = max(largest_component_size, component_size[root_u]);
        num_components--;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Initialize the Union-Find structure
    num_components = n;
    largest_component_size = 1;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        component_size[i] = 1;
    }

    // Process each new road
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        // Union the two cities if they are in different components
        unite(a, b);

        // Output the current number of components and the largest component size
        cout << num_components << " " << largest_component_size << "\n";
    }

    return 0;
}
