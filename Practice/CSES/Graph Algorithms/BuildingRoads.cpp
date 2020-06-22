/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
using namespace std;
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb push_back
vector<int> graph[200001];
int visited[200001];
void dfs(int node)
{
  visited[node] = 1;
  for (auto it : graph[node])
  {
    if (!visited[it])
      dfs(it);
  }
}
int main()
{
  REDBULL
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  int count = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
      count++;
      v.pb(i);
    }
  }

  if (count == 1)
    cout << 0 << endl;
  else {
    cout << count - 1 << endl;
    for (int i = 0; i < count - 1; i++)
      cout << v[i] << " " << v[i + 1] << endl;

  }




  return 0;
}