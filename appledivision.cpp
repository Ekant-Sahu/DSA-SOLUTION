#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve(int i, int n, long long sum1, long long sum2, vector<long long> &v, long long &mi)
{
    if (i == n)
    {
        mi = min(mi, abs(sum1 - sum2));
        return;
    }
    solve(i + 1, n, sum1 + v[i], sum2, v, mi);
    solve(i + 1, n, sum1, sum2 + v[i], v, mi);
}

int main()
{
    int n;
    cin >> n;

    vector<long long> weights(n);
    long long totalSum = 0;

    // Input apple weights and calculate the total sum
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    long long mi = LLONG_MAX;

    solve(0, n, 0, 0, weights, mi);
    cout << mi << endl;

    return 0;
}
