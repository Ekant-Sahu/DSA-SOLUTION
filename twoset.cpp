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
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;
    if (sum % 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<int> v;
        sum /= 2;
        while (sum > n)
        {
            v.push_back(n);
            sum -= n;
            n--;
        }
        v.push_back(sum);
        cout << "YES" << endl;
        cout << v.size() << endl;
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        cout << n - 1 << endl;
        while (n > 0)
        {
            if (sum != n)
            {
                cout << n << " ";
            }
            n--;
        }
    }
}