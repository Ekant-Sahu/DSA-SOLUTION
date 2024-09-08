#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

int reverse(int x)
{
    int r, i = 0;
    int num = 1;
    bool neg = false;

    if (x < 0)
    {
        x = abs(x);
        cout << x << endl;
        neg = true;
    }
    int temp = x;
    while (temp > 1)
    {
        i++;
        temp = temp / 10;
    }
    i--;
    cout << i << endl;
    temp = x;
    while (temp > 1)
    {
        r = temp % 10;
        cout << r << "*" << pow(10, i) << "+" << num << endl;
        num += r * pow(10, i);
        temp = temp / 10;
        i--;
    }
    if (neg)
    {
        return -num;
    }
    else
    {
        return num;
    }
}
int main()
{
    cout << reverse(-321);
}