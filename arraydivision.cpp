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
    vector<long long> num(n);
    long long maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        maxValue = max(maxValue, num[i]);
    }
    long long left = maxValue;
    long long right = 1e18;
    long long answer = 1e18;
    while (left <= right)
    {
        long long mid = (right + left) / 2;
        int block = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + num[i] > mid)
            {
                sum = 0;
                block++;
            }
            sum += num[i];
        }
        if (block > t)
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
