#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to generate Gray code for a given n
vector<string> grayCode(int n)
{
    if (n == 0)
    {
        return {""};
    }
    if (n == 1)
    {
        return {"0", "1"};
    }

    // Get the Gray code for n-1
    vector<string> prev_gray = grayCode(n - 1);

    // Create the new Gray code list
    vector<string> result;

    // Prefix '0' to the first half
    for (const string &code : prev_gray)
    {
        result.push_back("0" + code);
    }

    // Prefix '1' to the second half (in reverse order)
    for (auto it = prev_gray.rbegin(); it != prev_gray.rend(); ++it)
    {
        result.push_back("1" + *it);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> result = grayCode(n);

    // Output the Gray code
    for (const string &code : result)
    {
        cout << code << endl;
    }

    return 0;
}