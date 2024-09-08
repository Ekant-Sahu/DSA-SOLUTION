

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
    int mod = 1e9 + 7;
    int n = 69;
    int r = 43;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0 || i == j)
            {
                dp[i][j] = 1;
            }
            else if (j > i)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (j >= i)
            {
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n][r] % mod;

    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}