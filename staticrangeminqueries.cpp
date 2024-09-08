#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

const int MAX_N = 100'005;
const int LOG = 17;
int bin_log[MAX_N];
int m[MAX_N][LOG];
int a[MAX_N];

int querey(int l, int r)
{
    int length = r - l - 1;
    int k = bin_log[length];
    return min(m[l][k], m[r - (1 << k) + 1][k]);
}

int main()
{
    int n;
    cin >> n;
    bin_log[1] = 0;
    for (int i = 2; i < n; i++)
    {
        bin_log[i] = bin_log[i / 2] + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for (int i = 1; i < LOG; i++)
    {
        for (int k = 0; i + (1 << k) - 1 < n; k++)
        {
            m[k][i] = min(m[k][i - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << querey(l, r) << "\n";
    }
}