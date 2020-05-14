#include<bits/stdc++.h>
using namespace std;

#define log 15
#define int long long int

int level[10007];
int	lca[10007][log];

vector<int> graph[10007];

void dfs(int node, int parent, int h)
{
	level[node] = h;
	lca[node][0] = parent;

	for (int i = 1; i < log; i++ )
	{
		if (lca[node][i - 1] != -1)
		{
			lca[node][i] = lca[lca[node][i - 1]][i - 1];
		}
	}

	for (int child : graph[node])
	{
		if (child == parent)
			continue;
		dfs(child, node, h + 1);
	}


}
int LCA(int u, int v)
{

	if (level[u] > level[v])
		swap(u, v);

	for (int i = log - 1 ; i >= 0; i--)
	{

		if (lca[v][i] != -1 && level[lca[v][i]] >= level[u])
		{

			v = lca[v][i];
		}
	}
	if (v == u)
	{
		return v;
	}
	else
	{
		for (int i = log - 1; i >= 0; i--)
		{
			if (lca[u][i] != lca[v][i])
			{

				v = lca[v][i];
				u = lca[u][i];
			}
		}
		return lca[u][0];
	}

}


int32_t main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int v;
			cin >> v;
			graph[i].push_back(v);
			graph[v].push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < log; j++)
		{
			lca[i][j] = -1;
		}
	}
	dfs(0, 0, 0);
	int q;
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << endl;

	}

	return 0;
}