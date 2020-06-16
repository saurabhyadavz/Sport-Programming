/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
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
#define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"

bool inside(int l, int r, int l1, int r1)
{
  if (l1 >= l && l1 <= r && r1 >= l && r1 <= r)
    return true;
  return false;

}
int32_t main()
{
  REDBULL

  int n;
  cin >> n;
  vector<pair<int, int>> v;
  loop(i, 0, n)
  {
    int u1, v1;
    cin >> u1 >> v1;
    v.push_back(make_pair(u1, true));
    v.push_back(make_pair(v1, false));
  }
  sort(v.begin(), v.end());
  int count = 0, max1 = 0;
  for (int i = 0; i < 2 * n; i++)
  {
    count += v[i].second ? 1 : -1;
    max1 = max(max1, count);
  }
  cout << max1 << endl;
  return 0;
}
