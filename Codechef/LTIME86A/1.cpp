// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native") // yandex

#include "bits/stdc++.h"
using namespace std;
#ifndef LOCAL
#define endl '\n'
#endif

#define fr(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, a, b) for(int i = a; i >= b; i--)
#define pf push_front
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef long double f80;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int pct(int x) { return __builtin_popcount(x); }
int pct(ll x) { return __builtin_popcountll(x); }
int bt(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))
int bt(ll x) { return 63 - __builtin_clzll(x); } // floor(log2(x))
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
ll cdiv(ll a, ll b) { return a / b + !(a < 0 || a % b == 0); }
int nxt_C(int x) { int c = x & -x, r = x + c; return (((r ^ x) >> 2) / c) | r; }
ll nxt_C(ll x) { ll c = x & -x, r = x + c; return (((r ^ x) >> 2) / c) | r; }

vector<int> get_bits(int mask) {
	vector<int> bb;
	while (mask) { int b = bt(mask); bb.pb(b); mask ^= (1 << b); }
	reverse(all(bb));
	return bb;
}

int get_mask(vector<int> v) {
	int mask = 0;
	for (int x : v) { mask ^= (1 << x); }
	return mask;
}

template<typename T>
void uniq(vector<T> &v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r) {
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

void sc() {}

template <typename Head, typename... Tail>
void sc(Head &H, Tail &... T) { cin >> H; sc(T...); }

#ifdef LOCAL
#define debug(...) cerr << "[L:" << _LINE_ << "][" << #_VA_ARGS_ << "]:", debug_out(_VA_ARGS_)
#else
#define debug(...) 42
#endif

// #ifndef LOCAL
// string to_string(__int128 x) {
// 	string s = "";
// 	bool neg = 0;
// 	if(x < 0) { s += "-"; neg = 1; x = -x; }
// 	if(!x) s += '0';
// 	while(x) {
// 		int rem = x % 10;
// 		s += to_string(rem);
// 		x /= 10;
// 	}
// 	reverse(s.begin() + neg, s.end());
// 	return s;
// }
// #endif

const int mod = 1e9 + 7; // 998244353;

int pwr(int a, ll b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

/*
	Lookout for overflows!!
	Check array sizes!!
	Clear before test cases!!
	Use the correct modulo!!
	Check for corner cases!!
	Are you forgetting something?!
	Read problem statement carefully!!!
*/

const int N = 3e6 + 5;
ll g[N];
ll pt[N];
ll pre[N];
int c = 0;

int get(ll r) {
	if (r == 0) return 0;
	int idx = lower_bound(pt + 1, pt + c + 1, r) - pt - 1;
	ll ii = ((idx + 1) * 1LL * (idx + 1)) % mod;
	ll ans = (pre[idx] + (r - pt[idx]) * ii) % mod;
	return ans;
}

void solve() {
	ll l, r;
	sc(l, r);
	cout << (get(r) - get(l - 1) + mod) % mod << endl;
}

void _pre() {
	ll r = 1e10;
	int i = 0;
	while (1) {
		i++;
		if (i == 1) g[i] = 1;
		else g[i] = 1 + g[i - g[g[i - 1]]];
		pt[i] = pt[i - 1] + g[i];
		ll ii = (i * 1LL * i) % mod;
		pre[i] = (pre[i - 1] + g[i] * ii) % mod;
		if (pt[i] >= r) break;
	}
	c = i;
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	_pre();
	int t = 1;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}