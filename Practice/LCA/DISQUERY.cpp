/*

Question link:https://www.spoj.com/problems/DISQUERY/

*/




#include<bits/stdc++.h>
using namespace std;

#define MAX 100001
#define log 17
#define int long long int
int level[MAX];
int	lca[MAX][log];
int MinWeight[MAX][log];
int MaxWeight[MAX][log];

vector<pair<int, int>> graph[MAX];

void dfs(int node, int parent, int h, int edge_weight)
{
	level[node] = h;
	lca[node][0] = parent;
	if (parent != -1)
	{
		MinWeight[node][0] = edge_weight;
		MaxWeight[node][0] = edge_weight;
	}

	for (int i = 1; i < log; i++ )
	{
		if (lca[node][i - 1] != -1)
		{
			lca[node][i] = lca[lca[node][i - 1]][i - 1];
			MinWeight[node][i] = min(MinWeight[node][i - 1], MinWeight[lca[node][i - 1]][i - 1]);
			MaxWeight[node][i] = max(MaxWeight[node][i - 1], MaxWeight[lca[node][i - 1]][i - 1]);
		}
	}

	for (auto child : graph[node])
	{
		if (child.first == parent)
			continue;

		dfs(child.first, node, h + 1, child.second);
	}



}

void LCA(int u, int v)
{
	int minans = 1000000000000000, maxans = -1;

	if (level[u] > level[v])
		swap(u, v);

	// cout << "v " << v << endl;
	// cout << "lca[0] " << lca[v][0] << endl;
	for (int i = log - 1 ; i >= 0; i--)
	{
		// cout << lca[v][i] << endl;
		if (lca[v][i] != -1 && level[lca[v][i]] >= level[u])
		{
			// cout << "i " << i << endl;
			minans = min(minans, MinWeight[v][i]);
			maxans = max(maxans, MaxWeight[v][i]);
			v = lca[v][i];
		}
	}
	if (v == u)
	{
		cout << minans << " " << maxans << endl;

	}
	else
	{
		for (int i = log - 1; i >= 0; i--)
		{
			if (lca[u][i] != lca[v][i])
			{
				// cout << u << "/ " << v << endl;
				minans = min(minans, min(MinWeight[u][i], MinWeight[v][i]));
				maxans = max(maxans, max(MaxWeight[u][i], MaxWeight[v][i]));
				v = lca[v][i];
				u = lca[u][i];
			}
		}
		minans = min(minans, min(MinWeight[u][0], MinWeight[v][0]));
		maxans = max(maxans, max(MaxWeight[u][0], MaxWeight[v][0]));
		cout << minans << " " << maxans << endl;
	}
}
int32_t main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x1, x2, w;
		cin >> x1 >> x2 >> w;
		graph[x1].push_back({x2, w});
		graph[x2].push_back({x1, w});
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= log; j++)
		{
			MinWeight[i][j] = 1000000000000;
			MaxWeight[i][j] = -1;
			lca[i][j] = -1;
		}
	}

	dfs(1, -1, 0, 0);

	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		LCA(a, b);
	}
	return 0;
}