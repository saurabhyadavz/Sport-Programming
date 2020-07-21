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
#define MAX 10000000000000
string a;
void perform(int len)
{
	for (int i = 0; i <= len; i++)
	{
		if (a[i] == '1')
			a[i] = '0';
		else
			a[i] = '1';
	}
	string ans;
	for (int i = len; i >= 0; i--)
		ans += a[i];
	for (int i = 0; i <= len; i++)
		a[i] = ans[i];
	// return ans;
}
void solve()
{
	int n;
	cin >> n;

	string b;
	cin >> a >> b;
	vector<int> v;
	int glo = 0;
	int start = 0, end = n - 1;
	int startt = 0, endd = n - 1;
	int end2 = n - 1;
	int count = 0;
	while (true)
	{

		char check1 = a[end], check2 = a[start];
		if (count % 2 != 0)
		{
			check1 = (check1 == '0') ? '1' : '0';
			check2 = (check2 == '0') ? '1' : '0';
		}
		if (b[end2] != check1)
		{
			if (b[end2] == check2)
				v.pb(1);
			v.pb(end2 + 1);
			if (start == startt)
			{
				startt++;
				start = endd;
				end = startt;
			}
			else {
				endd--;
				start = startt;
				end = endd;
			}
			count++;
			end2--;
		}
		else {
			end2--;
			if (end == startt)
				startt++, end = startt;
			else
				endd--, end = endd;
		}
		if (end2 < 0)
			break;

	}
	cout << v.size() << " ";
	for (auto it : v)
		cout << it << " ";
	cout << endl;
}
int32_t main()
{
	REDBULL
	w
	solve();

	return 0;
}