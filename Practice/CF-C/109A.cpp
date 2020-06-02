/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

// https://codeforces.com/contest/401/problem/C

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
typedef pair<int, int> pi;

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
#define unmp(name) unordered_map<int,int,custom_hash> name
#define MAX 100000


int32_t main()
{
	REDBULL
	int n;
	cin >> n;
	string check1 = "", check2 = "";
	int len1 = n / 7;
	int rem1 = n % 7;
	if (rem1 != 0)
		len1++;
	else {
		loop(i, 0, len1)
		check1 += '7';
	}

	int len2 = n / 4;
	int rem2 = n % 4;
	if (rem2 != 0)
		len2++;
	else {
		loop(i, 0, len2)
		check2 += '4';
	}

	int sum = rem1;
	int store1 = 0;
	while (len1 != 0)
	{
		if (sum % 4 == 0)
		{
			store1 = sum / 4;
			len1--;
			break;
		}
		sum += 7;
		len1--;
	}

	sum = rem2;
	int store2 = 0;
	while (len2 != 0)
	{
		if (sum % 7 == 0)
		{
			store2 = sum / 7;
			len2--;
			break;
		}
		sum += 4;
		len2--;
	}
	string s = "";
	if (store1 != 0 )
	{
		loop(i, 0, store1)
		s += '4';
		loop(i, 0, len1)
		s += '7';


	}
	string s1 = "";
	if (store2 != 0 )
	{
		loop(i, 0, len2)
		s1 += '4';
		loop(i, 0, store2)
		s1 += '7';


	}


	if (s1 == "" && s == "" && check1 == "" && check2 == "")
	{

		cout << -1 << endl;

	}

	else
	{

		set<pair<int, string>> set;
		if (check1 != "")
			set.insert(make_pair(check1.size(), check1));
		if (check2 != "")
			set.insert(make_pair(check2.size(), check2));
		if (s != "")
			set.insert(make_pair(s.size(), s));
		if (s1 != "")
			set.insert(make_pair(s1.size(), s1));
		auto it = set.begin();
		cout << (*it).second << endl;

	}



	return 0;
}