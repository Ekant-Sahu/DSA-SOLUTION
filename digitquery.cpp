#include <iostream>
using namespace std;

char find_digit(long long k)
{
    long long digit_length = 1;
    long long count = 9;
    long long start = 1;

    // Find the range of numbers where the k-th digit lies
    while (k > digit_length * count)
    {
        k -= digit_length * count;
        digit_length++;
        count *= 10;
        start *= 10;
    }

    // Find the actual number that contains the k-th digit
    long long num = start + (k - 1) / digit_length;
    long long digit_index = (k - 1) % digit_length;

    // Convert the number to a string and return the appropriate digit
    string num_str = to_string(num);
    return num_str[digit_index];
}

int main()
{
    int q;
    cin >> q;

    // Process each query
    for (int i = 0; i < q; i++)
    {
        long long k;
        cin >> k;
        cout << find_digit(k) << endl;
    }

    return 0;
}
