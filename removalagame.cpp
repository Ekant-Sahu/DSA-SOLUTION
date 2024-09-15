#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9

int main()
{
    int n;
    cin >> n;
    vector<long long> values(n);
    vector<vector<long long>> dp(n, vector<long long>(n));
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        dp[i][i] = values[i];
        sum += values[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = max(values[i] - dp[i + 1][j], values[j] - dp[i][j - 1]);
        }
    }
    cout << (sum + dp[0][n - 1]) / 2;
}