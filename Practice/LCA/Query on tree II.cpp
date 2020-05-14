#include<bits/stdc++.h>
using namespace std;

#define MAX 10007
#define log 15
#define int long long int
int level[MAX];
int	lca[MAX][log];
int dist[MAX][log];


vector<pair<int, int>> graph[MAX];

void dfs(int node, int parent, int h, int edge_weight)
{
	level[node] = h;
	lca[node][0] = parent;
	if (parent != -1)
	{
		dist[node][0] = edge_weight;
	}

	for (int i = 1; i < log; i++ )
	{
		if (lca[node][i - 1] != -1)
		{
			lca[node][i] = lca[lca[node][i - 1]][i - 1];
			dist[node][i] = dist[node][i - 1] + dist[lca[node][i - 1]][i - 1];
			// MaxWeight[node][i] = max(MaxWeight[node][i - 1], MaxWeight[lca[node][i - 1]][i - 1]);
		}
	}

	for (auto child : graph[node])
	{
		if (child.first == parent)
			continue;

		dfs(child.first, node, h + 1, child.second);
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

void distance(int u, int v)
{
	int ans = 0;

	if (level[u] > level[v])
		swap(u, v);

	for (int i = log - 1 ; i >= 0; i--)
	{

		if (lca[v][i] != -1 && level[lca[v][i]] >= level[u])
		{
			ans += dist[v][i];
			v = lca[v][i];
		}
	}
	if (v == u)
	{
		cout << ans << endl;

	}
	else
	{
		for (int i = log - 1; i >= 0; i--)
		{
			if (lca[u][i] != lca[v][i])
			{
				ans += dist[u][i] + dist[v][i];
				v = lca[v][i];
				u = lca[u][i];
			}
		}
		ans += dist[u][0] + dist[v][0];
		cout << ans << endl;
	}
}
void kth(int a, int b, int k)
{
	k--;
	int let = LCA(a, b);
	// cout << let << endl;
	int level1 = level[a] - level[let];
	int level2 = level[b] - level[let];
	int total = level1 + level2;
	if (k <= level1)
	{
		int find = a;
		if (k > 0)
		{
			while (true)
			{
				int i = log2(k);
				int near = pow(2, i);
				a = lca[a][i];

				k -= near;
				if (k <= 0)
					break;
			}
		}

		cout << a << endl;

	}
	else
	{
		k = total - k;

		if (k > 0)
		{
			while (true)
			{
				int i = log2(k);
				int near = pow(2, i);
				b = lca[b][i];
				k -= near;
				if (k <= 0)
					break;

			}
		}

		cout << b << endl;
	}
}
int32_t main()
{

	int t;
	cin >> t;
	while (t--)
	{	int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
		}

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
				dist[i][j] = 0;
				lca[i][j] = -1;
			}
		}

		dfs(1, -1, 0, 0);

		string s;
		while (cin >> s)
		{
			int a, b;

			if (s == "DIST")
			{
				cin >> a >> b;
				distance(a, b);
			}
			else if (s == "KTH")
			{
				int k;
				cin >> a >> b;
				cin >> k;
				kth(a, b, k);
			}
			else
				break;
		}

		if (t > 0)
			printf("\n");

	}

	return 0;
}