
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

// Question link: https://codeforces.com/contest/522/problem/A

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
int ans = INT_MIN;
void dfs(int u, int d) {

	visited[u] = 1;
	depth[u] = d;
	ans = max(ans, d);
	for (int child : v1[u]) {
		if (visited[child] == 1)
			continue;
		dfs(child, d + 1);
	}


}
int32_t main()
{

	REDBULL
	int n;
	cin >> n;
	map<string, int> mp;
	mp["polycarp"] = 1;
	int count = 2;
	loop(i, 0, n) {
		string s[3];
		loop(j, 0, 3)
		cin >> s[j];
		transform(s[0].begin(), s[0].end(), s[0].begin(), ::tolower);
		transform(s[2].begin(), s[2].end(), s[2].begin(), ::tolower);
		if (mp.find(s[2]) == mp.end()) {
			mp[s[2]] = count;
			count++;
		}
		if (mp.find(s[0]) == mp.end()) {
			mp[s[0]] = count;
			count++;
		}
		v1[mp[s[0]]].pb(mp[s[2]]);
		v1[mp[s[2]]].pb(mp[s[0]]);
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}