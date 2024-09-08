#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<long long> lis(n + 1);
    vector<long long> sumlis(n + 1);
    long long sum = 0;
    lis[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> lis[i];
        sum = sum + lis[i];
        sumlis[i] = sum;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cout << sumlis[b] - sumlis[a - 1] << endl;
    }
}