#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <string>
#include<math.h>
#include<algorithm>
#include<numeric>


int main()
{
	int n, m, k, count = 0;
	vector<long long> desired;
	vector<long long> available;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		desired.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		long long a;
		cin >> a;
		available.push_back(a);
	}
	sort(desired.begin(), desired.end());
	sort(available.begin(), available.end());
	int i = 0, j = 0;
    while(i<n)
    {
        while(j<m && available[j]<desired[i] - k) j++;
        if(abs(available[j] - desired[i])<=k){
            count++;
            i++;
            j++;
        }
        else
            i++;
    }
	cout << count;
	return 0;
}