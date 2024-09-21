#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <stdio.h>
#define INF 1e9

const int N = 1000000;
const int m = 1000000007;

int arr[N] = {2, 0, 2};

// recersive implementation

int main()
{

    int n = 4, max = 10;
    vector<int> weight = {4, 8, 6, 1};
    vector<vector<int>> dp(n + 1, vector<int>(max + 1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
}
