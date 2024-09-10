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
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1);
    vector<int> number(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
        pos[number[i]] = i;
    }
    int answer = 1;
    for (int i = 1; i < n; i++)
    {
        answer += (pos[i] > pos[i + 1]);
    }
    int l, r;
    set<pair<int, int>> updatedPair;
    while (q--)
    {
        cin >> l >> r;
        if (number[l] + 1 <= n)
        {
            updatedPair.insert({number[l], number[l] + 1});
        }
        if (number[l] - 1 <= n)
        {
            updatedPair.insert({number[l] - 1, number[l]});
        }
        if (number[r] + 1 <= n)
        {
            updatedPair.insert({number[r], number[r] + 1});
        }
        if (number[r] - 1 <= n)
        {
            updatedPair.insert({number[r] - 1, number[r]});
        }
        for (auto swapped : updatedPair)
        {
            answer -= pos[swapped.first] > pos[swapped.second];
        }
        swap(number[l], number[r]);
        pos[number[l]] = l;
        pos[number[r]] = r;
        for (auto swapped : updatedPair)
        {
            answer += pos[swapped.first] > pos[swapped.second];
        }
        cout << answer << endl;
        updatedPair.clear();
    }
}