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
#define MAX 200000
int tree[5 * MAX + 10];
int arr[MAX];


void build(int node, int s, int e)
{
  if (s == e)
  {
    tree[node] = arr[s];
    return ;
  }
  build(2 * node, s, (s + e) / 2);
  build(2 * node + 1, 1 + (s + e) / 2, e);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int s, int e, int index, int value)
{
  if (s == e)
  {
    tree[node] += value;
    return;
  }
  if (index <= (s + e) / 2)
    update(2 * node, s, (s + e) / 2, index, value);
  else
    update(2 * node + 1, 1 + (s + e) / 2, e, index, value);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int s, int e, int l, int r)
{
  if (s > r || e < l)
    return 0;
  if (s >= l && e <= r)
    return tree[node];

  return (query(2 * node, s, (s + e) / 2, l, r) + query(2 * node + 1, 1 + (s + e) / 2, e, l, r));
}


void solve()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  loop(i, 0, n)
  {
    if (s[i] == '1')
      arr[i] = 1;
    else
      arr[i] = 0;
  }
  build(1, 0, n - 1);
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0 && i == 0)
    {
      int l = i + 1;
      int r = i + k;
      int check = query(1, 0, n - 1, l, r);
      if (check == 0)
      {
        count++;
        // cout << "ehr" << endl;
        update(1, 0, n - 1, i, 1);
      }
    }
    else if (i == n - 1 && arr[i] == 0)
    {
      int l = i - k;
      int r = i - 1;
      int check = query(1, 0, n - 1, l, r);
      if (check == 0)
      {
        // cout << "eh2r2" << endl;
        count++;
        update(1, 0, n - 1, i, 1);
      }
    }
    else if (arr[i] == 0)
    {
      int l1 = i - k;
      int r1 = i - 1;
      int l2 = i + 1;
      int r2 = i + k;
      int check1, check2 ;
      check1 = query(1, 0, n - 1, l1, r1);
      check2 = query(1, 0, n - 1, l2, r2);
      if (check1 == check2 && check1 == 0)
      {
        // cout << i << endl;
        // cout << "ehr3" << endl;
        count++;
        update(1, 0, n - 1, i, 1);
      }
    }
  }
  cout << count << endl;

}
int32_t main()
{
  REDBULL
  w
  solve();
  return 0;
}