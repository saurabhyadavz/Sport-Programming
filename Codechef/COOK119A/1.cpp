/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define fore(name)  for(auto it=name.begin();it!=name.end();it++)
#define w  int t;cin>>t;while(t--)
#define pb(x) push_back(x)
#define in(y) insert(y)
#define bitscount 32
#define make(x,y) make_pair(x,y)
#define LOAD_FACTOR_set(name) name.reserve(32768);name.max_load_factor(0.25);
#define LOAD_FACTOR_map(name) name.reserve(1024);name.max_load_factor(0.25);
#define lcm(a,b) ((a*b))/(__gcd(a,b))
// #define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"
typedef pair<int, int> pi;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ordered_justset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define unmp(name) unordered_map<int,int,custom_hash> name
#define MAX 10000000000000
vector<int> graph[300000];
vector<int> ans;
vector<int> check;
bool visit[300000];
void dfs(int node)
{
  visit[node] = true;
  check.pb(node);
  for (auto it : graph[node])
  {
    if (!visit[it])
    {
      dfs(it);
    }
  }
}
void solve()
{
  int n, m;
  cin >> n >> m;
  double a[n + 1], b[n + 1], c[n + 1];
  loop(i, 0, n)
  cin >> a[i + 1];
  loop(i, 0, n)
  cin >> b[i + 1];
  double max1 = -10000000000000.0;
  loop(i, 0, n)
  {
    c[i + 1] = a[i + 1] / b[i + 1];
    max1 = max(max1, c[i + 1]);
  }

  int visited[n + 1] = {};
  loop(i, 1, n + 1)
  {
    visit[i] = false;
    if (c[i] == max1)
      visited[i] = 1;
  }

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    if (visited[u] == 1 && visited[v] == 1)
    {
      graph[u].pb(v);
      graph[v].pb(u);
    }
  }

  ans.clear();
  for (int i = 1; i <= n; i++)
  {
    if (visited[i] == 1)
    {
      if (visit[i] == false)
      {
        check.clear();
        dfs(i);
        if (check.size() > ans.size())
        {
          ans = check;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;

  for (int i = 1; i <= n; i++)
    graph[i].clear();


}
int32_t main()
{
  REDBULL
  w
  solve();

  return 0;
}