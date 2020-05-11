// Question Link: https://www.spoj.com/problems/HIGHWAYS/

#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

#define log 10    // log2(MAX)

// Array to store the level of each node
int level[MAX];

int lca[MAX][log];
int minWeight[MAX][log];
int maxWeight[MAX][log];

// Vector to store tree
vector<int> graph[MAX];
// Array to store weight of nodes
int weight[MAX];

void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

// Pre-Processing to calculate values
// of lca[][], MinWeight[][] and MaxWeight[][]
void dfs(int node, int parent, int h)
{
	// Using recursion formula to calculate
	// the values of lca[][]
	lca[node][0] = parent;

	// Storing the level of each node
	level[node] = h;
	if (parent != -1)
	{
		minWeight[node][0] = min(weight[node], weight[parent]);
		maxWeight[node][0] = max(weight[node], weight[parent]);
	}

	for (int i = 1; i < log; i++)
	{
		if (lca[node][i - 1] != -1)
		{
			// Using recursion formula to calculate
			// the values of lca[][], MinWeight[][] and
			// MaxWeight[][]
			lca[node][i] = lca[lca[node][i - 1]][i - 1];
			minWeight[node][i] = min(minWeight[node][i - 1], minWeight[lca[node][i - 1]][i - 1]);
			maxWeight[node][i] = max(maxWeight[node][i - 1], maxWeight[lca[node][i - 1]][i - 1]);
		}
	}

	for (int i : graph[node])
	{
		if (i == parent)
			continue;
		dfs(i, node, h + 1);
	}

}

void findMinMaxWeight(int u, int v)
{

	int minWei = INT_MAX;
	int maxWei = INT_MIN;

	// The node which is present farthest
	// from the root node is taken as v
	// If u is farther from root node
	// then swap the two
	if (level[u] > level[v])
		swap(u, v);

	// Finding the ancestor of v
	// which is at same level as u
	for (int i = log - 1; i >= 0; i--)
	{
		if (lca[v][i] != -1 && level[lca[v][i]] >= level[u])
		{
			// Calculating Minimum and Maximum Weight
			// of node v till its 2^i-th ancestor
			minWei = min(minWei, minWeight[v][i]);
			maxWei = max(maxWei, maxWeight[v][i]);
			v = lca[v][i];
		}
	}

	// If u is the ancestor of v
	// then u is the LCA of u and v
	if (v == u)
	{
		cout << minWei << " " << maxWei << endl;
	}
	else
	{
		// Finding the node closest to the root which is
		// not the common ancestor of u and v i.e. a node
		// x such that x is not the common ancestor of u
		// and v but lca[x][0] is
		for (int i = log - 1; i >= 0; i--)
		{
			if (lca[v][i] != lca[u][i])
			{
				// Calculating the minimum of MinWeight of v to its
				// 2^i-th ancestor and MinWeight of u to its 2^i-th ancestor
				minWei = min(minWei, min(minWeight[v][i], minWeight[u][i]));
				// Calculating the maximum of MaxWeight of v to its
				// 2^i-th ancestor and MaxWeight of u to its 2^i-th ancestor
				maxWei = max(maxWei, max(maxWeight[v][i], maxWeight[u][i]));

				v = lca[v][i];
				u = lca[u][i];
			}
		}
		// Calculating the Minimum of first ancestor of u and v
		minWei = min(minWei, min(minWeight[v][0], minWeight[u][0]));
		// Calculating the maximum of first ancestor of u and v
		maxWei = max(maxWei, max(maxWeight[v][0], maxWeight[u][0]));

		cout << minWei << " " << maxWei << endl;

	}
}

// Driver Code
int main()
{

	// Number of nodes
	int n = 5;

	// Add edges
	addEdge(1, 2);
	addEdge(1, 5);
	addEdge(2, 4);
	addEdge(2, 3);

	weight[1] = -1;
	weight[2] = 5;
	weight[3] = -1;
	weight[4] = 3;
	weight[5] = -2;

	// Initialising lca values with -1
	// Initialising MinWeight values with INT_MAX
	// Initialising MaxWeight values with INT_MIN
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < log; j++)
		{
			lca[i][j] = -1;
			minWeight[i][j] = INT_MAX;
			maxWeight[i][j] = INT_MIN;
		}

	}

	// Perform DFS
	dfs(1, -1, 0);

	findMinMaxWeight(1, 3);
	findMinMaxWeight(2, 4);
	findMinMaxWeight(3, 5);

	return 0;

}