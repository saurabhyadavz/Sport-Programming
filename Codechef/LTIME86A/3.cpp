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
#define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"
#define all(x) (x).begin(), (x).end()


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
typedef pair<int, int> pi;
#define UNMAP(name) unordered_map<int,int,custom_hash> name
#define MAX 3000000
int arr[MAX];
int pre[MAX];
vector<int> sum(MAX);
int siz = 0;
void solve()
{
	int l, r;
	cin >> l >> r;
	l = l - 1;
	int ans1 = 0, ans2 = 0;
	if (l != 0)
	{
		int check = lower_bound(sum.begin() + 1, sum.end()  , l) - sum.begin();
		int power = ((check + 1) * (check + 1)) % mod;
		ans1 = pre[check] + (l - sum[check] * power) % mod;
	}
	if (r != 0)
	{
		int check = lower_bound(sum.begin() + 1, sum.end() , r) - sum.begin() ;
		int power = ((check + 1) * (check + 1)) % mod;
		ans2 = pre[check] + (r - sum[check] * power) % mod;
	}
	cout << ans2 << endl;
	if (l == 0)
		ans1 = 0;
	if (r == 0)
		ans2 = 0;
	int ans = ans2 - ans1;
	if (ans < 0)
		ans = ans + mod;
	ans = ans % mod;
	cout << ans << endl;

}
int32_t main()
{
	// REDBULL
	arr[1] = 1;
	int i = 0;
	fill(all(sum), 0);
	while (true)
	{
		i = i + 1;
		if (i == 1)
		{
			arr[i] = 1;
			sum[i] = sum[i - 1] + arr[i];
			pre[i] = pre[i - 1] + (arr[i] % mod * i % mod * i % mod) % mod;
		}
		else
		{
			arr[i] = 1 + arr[i - arr[arr[i - 1]]];
			sum[i] = sum[i - 1] + arr[i];
			pre[i] = pre[i - 1] + (arr[i] % mod * i % mod * i % mod) % mod;
		}

		if (sum[i] >= 10000000000)
			break;
	}
	siz = i;
	sum.resize(siz);

	w
	solve();

	return 0;
}