#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <utility>
#define INF 1e18

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    long long left = 0;
    long long right = 1e18;
    long long answer = 1e18;
    while (left <= right)
    {
        long long mid = (right + left) / 2;
        long long product = 0;
        for (int i = 0; i < n; i++)
        {
            product += min(mid / time[i], (long long)1e9);
        }
        if (product < t)
        {
            left = mid + 1;
        }
        else
        {
            if (mid < answer)
                answer = mid;
            right = mid - 1;
        }
    }
    cout << answer << endl;
}
