
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
#define w()  int t;cin>>t;while(t--)
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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ordered_justset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct HASH {
	size_t operator()(const pair<int, int>&x)const {
		return ((int)x.first) ^ (((int)x.second) << 32);
	}
};
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

struct Query {

	int L;
	int R;
	int index;
	int c;
	int temp;
	int lca;
};

#define maxN 20


vector<int> graph[400001];
int ft[800001], start[400001], ender[400001];
int number[400001];
int nodefre[400001], freq[400001], arr[400001];
int timer;
int ans[400001];
int blk_sz = 500;
int LCA[400001][maxN];
int level[400001], block1[400001];


bool compare(Query x, Query y)
{
	if (x.L / blk_sz != y.L / blk_sz)
		return x.L / blk_sz < y.L / blk_sz;

	return x.R < y.R;
}

void dfs(int node, int p, int h) {

	level[node] = h;
	ft[timer] = node;
	start[node] = timer;
	timer++;
	LCA[node][0] = p;
	for (int child : graph[node]) {
		if (child != p) {
			dfs(child, node, h + 1);
		}
	}
	ft[timer] = node;
	ender[node] = timer;
	timer++;

}

void initLCA(int n)
{
	for (int j = 1; j < maxN; j++)
	{
		for (int i = 1; i <= n; i++)
			if (LCA[i][j - 1] != -1)
			{
				LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
			}
	}
}
int get1(int ind) {
	return (ind + blk_sz - 1) / blk_sz;
}
int query(int l, int r)
{
	int sum = 0;
	int LB, RB;
	LB = get1(l);
	RB = get1(r);
	if (LB == RB) {
		loop(i, l, r + 1) {
			sum += arr[i];
		}
	}
	else {
		loop(i, l, LB * blk_sz + 1)
		sum += arr[i];
		loop(i, LB + 1, RB)
		sum += block1[i];
		loop(i, RB * blk_sz, r + 1)
		sum += arr[i];

	}
	return sum;
}
int getlca(int a , int b)
{
	if (level[a] > level[b])
		swap(a , b);

	int d = level[b] - level[a];
	int f = 0;
	while (d)
	{
		if (d & 1)
			b = LCA[b][f];

		d >>= 1;
		f++;
	}

	if (a == b) return a;

	for (int j = maxN - 1; j >= 0; j--)
		if (LCA[a][j] != -1 && (LCA[a][j] != LCA[b][j]))
			a = LCA[a][j] , b = LCA[b][j];

	return LCA[a][0];
}
void add(int a, int c) {
	int node = ft[a];
	nodefre[node]++;
	if (nodefre[node] == 1)
	{
		freq[number[node]]++;
		if (freq[number[node]] >= 1)
		{


			block1[get1(number[node])] += (1 - arr[number[node]]);

			arr[number[node]] = 1;
		}

	}
	else
	{
		freq[number[node]]--;
		if (freq[number[node]] <= 0)
		{

			block1[get1(number[node])] += (0 - arr[number[node]]);
			arr[number[node]] = 0;

		}
	}
}
void remove(int a, int c) {
	int node = ft[a];
	nodefre[node]--;
	if (nodefre[node] == 1)
	{
		freq[number[node]]++;
		if (freq[number[node]] >= 1)
		{
			block1[get1(number[node])] += (1 - arr[number[node]]);

			arr[number[node]] = 1;
		}
	}
	else
	{
		freq[number[node]]--;
		if (freq[number[node]] <= 0)
		{
			block1[get1(number[node])] += (0 - arr[number[node]]);
			arr[number[node]] = 0;
		}
	}
}
void addthis(int node)
{
	freq[number[node]]++;
	if (freq[number[node]] >= 1)
	{
		block1[get1(number[node])] += (1 - arr[number[node]]);

		arr[number[node]] = 1;
	}
}

void removethis(int node)
{
	freq[number[node]]--;
	if (freq[number[node]] <= 0)
	{
		block1[get1(number[node])] += (0 - arr[number[node]]);

		arr[number[node]] = 0;
	}
}

bool sortbyfir(const pair<int, int> &a,
               const pair<int, int> &b)
{
	return (a.first < b.first);
}

int32_t main()
{

	REDBULL


	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> v ;
	vector<int> v1;

	loop(i, 1, n + 1) {
		int in; cin >> in; v.pb(make_pair(in, i));
		v1.pb(in);
	}
	sort(v.begin(), v.end(), sortbyfir);
	sort(v1.begin(), v1.end());
	loop(i, 0, n) {
		auto it = lower_bound(v1.begin(), v1.end(), v[i].first);
		number[v[i].second] = it - v1.begin() + 1;
	}




	loop(i, 0, n - 1) {
		int u1, v1;
		cin >> u1 >> v1;
		graph[u1].pb(v1);
		graph[v1].pb(u1);
	}

	loop(i, 1, n + 1)
	{
		loop(j, 0, maxN)
		{
			LCA[i][j] = -1;
		}
	}

	timer = 1;
	dfs(1, -1, 0);
	initLCA(n);
	Query qq[q];

	loop(i, 0, q)
	{
		int a, b, c;
		cin >> a >> b;
		if (start[a] > start[b])
			swap(a, b);

		int lca = getlca(a, b);
		// cout << a << " " << b << "->" << lca << endl;
		if (a != lca) {

			qq[i].L = ender[a];
			qq[i].R = start[b];
			qq[i].index = i;
			qq[i].lca = lca;
			qq[i].temp = 1;
			// cout << qq[i].L << " " << qq[i].R << " " << lca << endl;

		}
		else
		{
			qq[i].L = start[a];
			qq[i].R = start[b];
			qq[i].index = i;
			qq[i].lca = lca;
			qq[i].temp = 0;
			// cout << qq[i].L << " " << qq[i].R << " " << lca << endl;
		}


	}


	sort(qq, qq + q, compare);
	int currL = 1, currR = 0;
	loop(i, 0, q) {


		int L = qq[i].L , R = qq[i].R ;
		int temp = qq[i].temp;
		int lca = qq[i].lca;
		int c = 1;
		// cout << "currL " << currL << " " << "currR " << currR << endl;
		// cout << L << " " << R << " " << c << " " << lca << endl;
		while (currR < R) {

			currR++;
			add(currR, c);
		}
		while (currL > L) {

			currL--;
			add(currL, c);
		}


		while (currR > R )

		{
			remove(currR, c);
			currR--;
		}
		while (currL < L) {
			remove(currL, c);
			currL++;
		}

		if (temp == 1)
		{
			addthis(lca);
			ans[qq[i].index] = query(1, 100000);
			removethis(lca);
		}
		else
		{
			ans[qq[i].index] = query(1, 100000);


		}



	}
	loop(i, 0, q) {
		cout << ans[i] << endl;
	}
	return 0;
}