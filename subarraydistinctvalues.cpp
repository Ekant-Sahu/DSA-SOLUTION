#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <queue>
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int j = 0;
    map<int, int> occur;
    for (int i = 0; i < n; i++)
    {
        while (j < n && ((int)occur.size() < k) || occur.count(num[j]) > 0)
        {
            occur[num[j]]++;
            j++;
        }
        ans += j - i;
        occur[num[i]]--;
        if (occur[num[i]] == 0)
        {
            occur.erase(num[i]);
        }
    }
    cout << ans;
}
