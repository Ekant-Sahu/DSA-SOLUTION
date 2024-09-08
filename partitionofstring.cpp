#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

int partitionString(string s)
{
    int cnt = 0;
    int i = 0, j = 1;
    while (i < s.size())
    {
        if (s[i] == s[j])
        {
            cnt++;
            i = j;
            j++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}

int main()
{
    cout << partitionString("abacaba");
}