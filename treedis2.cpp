#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
    Tree(int n) : n(n)
    {
        graph.resize(n + 1);
        subtreeSize.resize(n + 1);
        distSum.resize(n + 1);
    }

    void addEdge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void calculateSubtreeSizesAndDistanceSum(int node, int parent)
    {
        subtreeSize[node] = 1; // Every node counts as part of its own subtree
        for (int child : graph[node])
        {
            if (child != parent)
            {
                calculateSubtreeSizesAndDistanceSum(child, node);
                subtreeSize[node] += subtreeSize[child];              // Add the size of the child's subtree to the current node
                distSum[node] += distSum[child] + subtreeSize[child]; // Add the distances from the child
            }
        }
    }

    void calculateAllDistances(int node, int parent)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                // Use the parent node's result to calculate the child's result
                distSum[child] = distSum[node] + (n - 2 * subtreeSize[child]);
                calculateAllDistances(child, node);
            }
        }
    }

    vector<long long> getDistanceSums()
    {
        return distSum;
    }

private:
    int n;
    vector<vector<int>> graph;
    vector<long long> subtreeSize;
    vector<long long> distSum;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Tree tree(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree.addEdge(a, b);
    }

    // Step 1: Calculate subtree sizes and sum of distances for the root (let's assume node 1 as the root)
    tree.calculateSubtreeSizesAndDistanceSum(1, -1);

    // Step 2: Calculate the sum of distances for all other nodes
    tree.calculateAllDistances(1, -1);

    // Step 3: Output the sum of distances for each node
    vector<long long> result = tree.getDistanceSums();
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
