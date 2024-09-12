#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> cust(n); // Resize vector to size n
    vector<int> roomAssigned(n, -1);           // Room assignment for each customer

    // Read input for customer check-in and check-out times
    for (int i = 0; i < n; i++)
    {
        cin >> cust[i].first.first >> cust[i].first.second;
        cust[i].second = i;
    }

    // Sort customers based on check-in time
    sort(cust.begin(), cust.end());

    int roomId = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rooms; // Min-heap to track room availability

    for (int i = 0; i < n; i++)
    {
        // If there's an available room and its check-out time is less than or equal to current check-in time
        if (!rooms.empty() && rooms.top().first <= cust[i].first.first)
        {
            roomAssigned[cust[i].second] = rooms.top().second; // Reuse room
            pair<int, int> x = rooms.top();
            rooms.pop();
            rooms.push(make_pair(cust[i].first.second, x.second)); // Update room's next availability time
        }
        else
        {
            // Assign a new room
            roomAssigned[cust[i].second] = roomId;
            rooms.push(make_pair(cust[i].first.second, roomId)); // Add new room's availability
            roomId++;
        }
    }

    cout << roomId - 1 << endl; // Output total number of rooms used
    for (auto x : roomAssigned)
    {
        cout << x << " "; // Output room assignments
    }
}
