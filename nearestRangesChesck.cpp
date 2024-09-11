#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

struct range
{
    int l, r, index;
    bool operator<(const range &other) const
    {
        if (l == other.l)
        {
            return r > other.r;
        }
        return l < other.l;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].l;
        cin >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());
    int maxEnd = 0;
    for (int i = 0; i < n; i++)
    {
        if (ranges[i].r <= maxEnd)
        {
            contained[ranges[i].index] = true;
        }
        maxEnd = max(maxEnd, ranges[i].r);
    }
    int minEnd = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ranges[i].r >= minEnd)
        {
            contains[ranges[i].index] = true;
        }
        minEnd = min(minEnd, ranges[i].r);
    }

    for (int x : contains)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x : contained)
    {
        cout << x << " ";
    }
}