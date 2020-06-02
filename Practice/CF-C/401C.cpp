
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

bool check(string s)
{
	int temp = 0;
	for (int i = 0; i < s.size();)
	{
		if (s[i] == '1')
		{
			int count = 0;
			while (i < s.size() && s[i] == '1')
			{
				count++;
				i++;
			}
			if (count >= 3)
			{
				temp = 1;
				break;
			}
		}
		else
		{
			int count = 0;
			while (i < s.size() && s[i] == '0')
			{
				count++;
				i++;
			}
			if (count >= 2)
			{
				temp = 1;
				break;
			}
		}

	}
	if (temp)
		return true;
	else
		return false;
}

int32_t main()
{
	REDBULL

	int a, b;
	cin >> a >> b;
	string s, s1;
	// cin >> s/;
	int a1 = a, b1 = b;
	while (true)
	{
		if (b > a && (b >= 2))
		{
			if (b >= 2)
				s += "11", b -= 2;
			if (a >= 1)
				s += '0', a -= 1;
		}
		else {
			if (b >= 1)
				s += '1', b -= 1;
			if (a >= 1)
				s += '0', a -= 1;
		}
		if (a <= 0 && b <= 0)
			break;


	}
	a = a1;
	b = b1;
	while (true)
	{
		if (b > a && (b >= 2))
		{
			if (b >= 2)
				s1 += "11", b -= 2;
			if (a >= 1)
				s1 += '0', a -= 1;
		}
		else {
			if (a >= 1)
				s1 += '0', a -= 1;
			if (b >= 1)
				s1 += '1', b -= 1;
		}
		if (a <= 0 && b <= 0)
			break;


	}



	if (check(s) && check(s1))
		cout << -1 << endl;
	else
	{
		if (check(s) == false)
		{
			cout << s << endl;
			// cout << "he" << endl;
		}
		else if (check(s1) == false)
			cout << s1 << endl;
	}



	return 0;
}