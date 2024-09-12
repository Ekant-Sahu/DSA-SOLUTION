#include <iostream>
#include <cmath>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <stack>
#define ll long long int

using namespace std;

// function to find a triplet whose sum = X
void solve(vector<ll> &arr, ll X, ll N)
{
    // vector to store the values along with their indices
    vector<vector<ll>> vec(N, vector<ll>(2));
    for (int i = 0; i < N; i++)
    {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1;
    }

    // Sort the vector in increasing order of the values
    sort(vec.begin(), vec.end());

    // Iterate for all possible values of first element
    for (ll ptr1 = 0; ptr1 < N - 2; ptr1++)
    {
        // Maintain two pointers for the second and third
        // element
        ll ptr2 = ptr1 + 1;
        ll ptr3 = N - 1;

        while (ptr2 < ptr3)
        {
            ll currentSum = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0];

            // If current sum is equal to X, then we have
            // found a triplet whose sum = X
            if (currentSum == X)
            {
                cout << vec[ptr1][1] << " " << vec[ptr2][1]
                     << " " << vec[ptr3][1] << "\n";
                return;
            }
            // Decrease the currentSum by moving ptr3 to
            // ptr3 - 1
            else if (currentSum > X)
            {
                ptr3--;
            }
            // Increase the currentSum by moving ptr2 to
            // ptr2 + 1
            else if (currentSum < X)
            {
                ptr2++;
            }
        }
    }

    // If no triplet has sum = X, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE";
}

int main()
{
    // Sample Input
    ll N, X;
    cin >> N >> X;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    solve(arr, X, N);

    return 0;
}