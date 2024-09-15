#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <stack>

int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < m + 1; i++)
    {
        dp[n][i] = m - i;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][m] = n - i;
    }
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
            }
        }
    }
    cout << dp[0][0] << endl;
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
}