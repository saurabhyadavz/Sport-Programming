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
#define all(x) (x).begin(), (x).end()
#define MAX 300000

void solve()
{
  string s;
  cin >> s;
  int check[s.size() + 1];
  stack<int> s1;
  for (int i = s.size() - 1 ; i >= 0; i--)
  {
    if (i == s.size() - 1)
    {
      check[i] = -1;
      if (s[i] == ')')
        s1.push(i);
    }
    else {
      if (s[i] == '(' && s1.size() == 0)
        check[i] = -1;
      else if (s[i] == '(' && s1.size() > 0)
        check[i] = s1.top(), s1.pop();
      else
        check[i] = check[i + 1], s1.push(i);


    }
  }
  int q;
  cin >> q;
  while (q--)
  {
    int a1;
    cin >> a1;
    a1--;
    if (check[a1] == -1)
      cout << -1 << endl;
    else
      cout << check[a1] + 1 << endl;
  }


}
int32_t main()
{
  REDBULL
  w
  solve();

  return 0;
}