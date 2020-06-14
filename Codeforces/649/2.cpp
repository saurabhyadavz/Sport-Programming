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
// #define MAX 200000
// int tree1[4 * MAX + 10];
// int tree2[4 * MAX + 10];
// int arr[MAX];
// void build1(int node, int s, int e)
// {
// 	if (s == e)
// 	{
// 		tree1[node] = arr[s];
// 		return ;
// 	}
// 	build1(2 * node, s, (s + e) / 2);
// 	build1(2 * node + 1, 1 + (s + e) / 2, e);
// 	tree1[node] = min(tree1[2 * node] , tree1[2 * node + 1]);
// }
// void build2(int node, int s, int e)
// {
// 	if (s == e)
// 	{
// 		tree2[node] = arr[s];
// 		return ;
// 	}
// 	build2(2 * node, s, (s + e) / 2);
// 	build2(2 * node + 1, 1 + (s + e) / 2, e);
// 	tree2[node] = max(tree2[2 * node] , tree2[2 * node + 1]);
// }


// int query1(int node, int s, int e, int l, int r)
// {
// 	if (s > r || e < l)
// 		return 0;
// 	if (s >= l && e <= r)
// 		return tree1[node];

// 	return min(query1(2 * node, s, (s + e) / 2, l, r) , query1(2 * node + 1, 1 + (s + e) / 2, e, l, r));
// }
// int query2(int node, int s, int e, int l, int r)
// {
// 	if (s > r || e < l)
// 		return 0;
// 	if (s >= l && e <= r)
// 		return tree2[node];

// 	return max(query2(2 * node, s, (s + e) / 2, l, r) , query2(2 * node + 1, 1 + (s + e) / 2, e, l, r));
// }
void solve()
{


	int n;
	cin >> n;
	int a[n];
	loop(i, 0, n)
	cin >> a[i];

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n - 1)
			v.pb(a[i]);
		else {
			if ((a[i] > a[i - 1] && a[i] < a[i + 1]) || (a[i] < a[i - 1] && a[i] > a[i + 1]))
			{

			}
			else
				v.pb(a[i]);
		}
	}
	cout << v.size() << endl;
	fore(v)
	{
		cout << *it << " ";
	}
	cout << endl;



}
int32_t main()
{
	REDBULL


	w{

		solve();

	}


	return 0;
}