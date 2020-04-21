
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
#define MAX 100000
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




int visited[10001];
vector<int> v1[1001];
int depth[20001];

void dfs(int u, int d) {

	visited[u] = 1;
	for (int child : v1[u]) {
		if (visited[child] == 1)
			continue;
		dfs(child, d + 1);
	}


}
int32_t main()
{

	REDBULL
	w() {


		int n, k;
		cin >> n >> k;
		int a[n], sum;

		int ans;
		ans = n;

		vector <pair<int, int>> v1;

		int count[2 * k + 10] = {};



		unordered_map <int, int, custom_hash> m1;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n / 2; i++)
		{
			m1[a[i] + a[n - i - 1]]++;

			int l = min(a[i], a[n - i - 1]);
			int r = max(a[i], a[n - i - 1]);

			int mi = 1 + l;
			int ma = k + r;
			v1.pb(make_pair(mi, ma));
		}


		int min2 = 2 * k, max2 = 2 * k;


		int li1, ri;

		for (int i = 0; i < n / 2; i++)
		{
			li1 = v1[i].first;
			count[li1] = count[li1] + 1;
			ri = v1[i].second;
			count[ri + 1] = count[ri + 1] - 1;

			if (li1 < min2)
				min2 = li1;
			if (ri > max2)
				max2 = ri;
		}

		for (int i = min2; i <= max2; i++)
			count[i] = count[i] + count[i - 1];

		for (int i = 2; i <= (2 * k); i++)
		{
			int temper1 = count[i];
			int temper2 = n / 2 - temper1;
			temper1 = temper1 - m1[i];

			int kemper = temper1 + 2 * temper2;

			if (kemper < ans) {

				ans = kemper;
			}
		}

		cout << ans << "\n";



	}

	return 0;
}