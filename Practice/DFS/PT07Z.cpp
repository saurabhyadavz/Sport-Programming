#include<bits/stdc++.h>
using namespace std;

vector<int> graph[20001];
int depth[20001];
int visited[20001];
void dfs(int node, int h)
{
	depth[node] = h;
	visited[node] = 1;
	for (int i : graph[node])
	{
		if (!visited[i])
		{
			dfs(i, h + 1);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	int d1 = depth[1];
	int node = 1;
	visited[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (depth[i] > d1)
		{
			d1 = depth[i] ;
			node = i;
		}
		visited[i] = 0;
	}

	dfs(node, 0);
	sort(depth + 1, depth + n + 1);
	cout << depth[n] << endl;
}