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
#define MAX_BITS 60
int store[64];
bool isKthBitSet(int n, int k)
{
	int power = store[k - 1];
	int check = n & power;
	if (check == 0)
	{
		return false;
	}
	else
		return true;
}

int** buildPrefixArray(int N, int arr[])
{

	int** P = new int*[N + 1];
	for (int i = 0; i <= N; ++i) {
		P[i] = new int[MAX_BITS + 1];
	}

	for (int i = 0; i <= MAX_BITS; i++) {
		P[0][i] = 0;
	}

	for (int i = 0; i < N; i++) {

		for (int j = 1; j <= MAX_BITS; j++) {
			// prefix sum from 0 to i for each bit
			// position jhas the value of sum from 0
			// to i-1 for each j
			if (i)
				P[i][j] = P[i - 1][j];

			// if jth bit set then increment P[i][j] by 1
			bool isJthBitSet = isKthBitSet(arr[i], j);
			if (!isJthBitSet) {
				P[i][j]++;
			}
		}
	}

	return P;
}


int answerQuery(int L, int R, int K, int** P)
{

	if (L)
		return P[R][K] - P[L - 1][K];
	else
		return P[R][K];
}

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> mp;
	int start = a[n - 1];
	mp[start]++;
	int flag = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		start = start | a[i];
		mp[start]++;
	}
	for (auto it : mp)
	{
		if (it.second > 1)
			flag = 1;
	}
	if (flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

}
int32_t main()
{
	REDBULL
	// cout << log2(1000000000000000000) << endl;

	for (int i = 0; i < 64; i++)
	{
		store[i] = pow(2, i);
	}
	w
	solve();

	return 0;
}