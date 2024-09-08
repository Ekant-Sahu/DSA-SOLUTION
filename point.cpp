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

long find_area(long x, long y, long a, long b, long p, long q)
{
    long area = (p - a) * (b - y) - (a - x) * (q - b);
    return area;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long x, y, a, b, p, q;
        cin >> x >> y >> a >> b >> p >> q;
        long area = find_area(x, y, a, b, p, q);
        // cout << area << endl;
        if (area > 0)
        {
            cout << "RIGHT" << endl;
        }
        else if (area < 0)
        {
            cout << "LEFT" << endl;
        }
        else
        {
            cout << "TOUCH" << endl;
        }
    }

    return 0;
}