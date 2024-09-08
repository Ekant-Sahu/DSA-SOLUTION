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
    int n, m, count = 0;
    cin >> n >> m;
    vector<int> pos(n);
    vector<int> number(n);
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
        number[i]--;
        pos[number[i]] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (pos[i] > pos[i + 1])
            count++;
    }
    count++;
    int a, b;
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> a >> b;
    //     if (number[a - 1] > number[b - 1])
    //     {
    //         count--;
    //         cout << count << endl;
    //     }
    //     else
    //     {
    //         count++;
    //         cout << count << endl;
    //     }
    // }
}