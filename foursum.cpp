#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

// Function to find a quadruplet whose sum = X
void solve(vector<ll> &arr, ll X, ll N)
{
    // Vector to store the values along with their indices
    vector<vector<ll>> vec(N, vector<ll>(2));
    for (int i = 0; i < N; i++)
    {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1; // Store the original 1-based index
    }

    // Sort the vector based on the values
    sort(vec.begin(), vec.end());

    // Iterate for all possible first and second elements
    for (ll ptr1 = 0; ptr1 < N - 3; ptr1++)
    {
        for (ll ptr2 = ptr1 + 1; ptr2 < N - 2; ptr2++)
        {
            // Maintain two pointers for the third and fourth elements
            ll ptr3 = ptr2 + 1;
            ll ptr4 = N - 1;

            while (ptr3 < ptr4)
            {
                ll currentSum = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0] + vec[ptr4][0];

                // If current sum equals X, then we have found a quadruplet
                if (currentSum == X)
                {
                    cout << vec[ptr1][1] << " " << vec[ptr2][1]
                         << " " << vec[ptr3][1] << " " << vec[ptr4][1] << "\n";
                    return; // Return if one solution is needed, remove to find all solutions
                }
                // Decrease the sum by moving ptr4 to the left
                else if (currentSum > X)
                {
                    ptr4--;
                }
                // Increase the sum by moving ptr3 to the right
                else
                {
                    ptr3++;
                }
            }
        }
    }

    // If no quadruplet has sum = X, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE";
}

int main()
{
    // Input
    ll N, X;
    cin >> N >> X;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Solve the problem
    solve(arr, X, N);

    return 0;
}
