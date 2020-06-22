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

  int parent[n + 1] = {};
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (q.size() != 0)
  {
    int p = q.front();
    q.pop();
    if (p == n)
      break;
    for (auto it : graph[p])
    {
      if (!visited[it])
      {
        parent[it] = p;
        q.push(it);
        visited[it] = 1;
      }
    }
  }

  if (visited[n] == 0)
  {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<int> path;
  int u = n;
  while (u > 0)
  {
    path.push_back(u);
    u = parent[u];
  }

  reverse(path.begin(), path.end());
  cout << path.size() << endl;
  for (int i = 0; i < path.size(); i++)
    cout << path[i] << " ";
  cout << endl;


  return 0;
}