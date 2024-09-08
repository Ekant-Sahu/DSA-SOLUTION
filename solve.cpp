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

bool solve(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] > 5)
        {
            if (arr[i] % 10 == 2)
            {
                arr[i] = arr[i] - 6;
            }
            else if (arr[i] % 10 == 4)
            {
                arr[i] = arr[i] - 2;
            }
            else if (arr[i] % 10 == 6)
            {
                arr[i] = arr[i] - 8;
            }
            else if (arr[i] % 10 == 8)
            {
                arr[i] = arr[i] - 4;
            }
            else if (arr[i] % 10 == 0 || arr[i] % 10 == 5)
            {
                return false; // iska bourdary condition check karna
            }
            else
            {
                arr[i] = arr[i] + (arr[i] % 10);
            }
        }
    }

    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            return false;
        }
        return true;
    }
}

int main()
{
    vector<int> array = {67, 48, 12, 13, 14};
    cout << solve(array);
}