#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 200001; // Maximum number of planets
const int LOG = 30;       // 2^30 > 10^9, sufficient for large k

// Precomputed table for binary lifting
int lift[MAX_N][LOG];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    // Reading the teleporters for each planet
    for (int i = 1; i <= n; i++)
    {
        cin >> lift[i][0]; // Direct teleporter destination for 1 jump
    }

    // Precompute binary lifting table
    for (int p = 1; p < LOG; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            lift[i][p] = lift[lift[i][p - 1]][p - 1];
        }
    }

    // Process each query
    while (q--)
    {
        int x, k;
        cin >> x >> k;

        // Perform binary lifting to find the planet after k jumps
        for (int p = 0; p < LOG; p++)
        {
            if (k & (1 << p))
            {
                x = lift[x][p]; // Jump 2^p steps if the p-th bit of k is set
            }
        }

        // Output the final planet
        cout << x << '\n';
    }

    return 0;
}
