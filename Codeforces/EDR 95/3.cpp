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
bool confirm(string check)
{
	if (check.size() == 0)
		return false;
	string s1, s2;
	s1 += check[check.size() - 1];

	for (int k = 0; k < check.size() - 1; k++)
	{
		s1 += check[k];
	}

	for (int k = 1; k < check.size(); k++)
	{
		s2 += check[k];
	}
	s2 += check[0];
	if (s1 == s2)
	{
		return true;
	}
	return false;

}
void solve()
{
	string s;
	cin >> s;
	map<int, int> mp;
	for (int i = 0; i < s.size(); i++)
	{
		int check = s[i] - '0';
		mp[check]++;
	}
	vector<int> v[10];
	for (int i = 0; i <= 9; i++)
	{
		for (int j = i + 1; j <= 9; j++)
		{
			if (mp[i] != 0 && mp[j] != 0)
			{
				if (mp[i] >= 1 && mp[j] >= 1 )
				{
					v[i].pb(j);
				}
			}
		}
	}
	int ans = MAX;
	for (int i = 0; i <= 9; i++)
	{

		for (int j = 0; j < v[i].size(); j++)
		{
			string check;
			char c1 = i + '0';
			char c2 = v[i][j] + '0';
			int count1 = mp[i];
			int count2 = mp[v[i][j]];
			int count3 = min(count1, count2);
			count1 = count3;
			count2 = count3;
			// cout << c1 << " " << c2 << endl;
			int ind1 = -1, ind2 = -1;
			for (int k = 0; k < s.size(); k++)
			{
				if (s[k] == c1 )
				{
					ind1 = k;
					break;
				}
			}
			int let = 0;
			for (int k = ind1; k < s.size(); k++)
			{
				if (let % 2 == 0 && s[k] == c1 && count1 != 0)
				{
					check += s[k];
					count1--;
					let++;
				}
				if (let % 2 != 0 && s[k] == c2 && count2 != 0)
				{
					check += s[k];
					count2--;
					let++;
				}

			}
			// cout << check << endl;
			bool ok = confirm(check);
			if (ok)
			{
				int ans1 = s.size() - check.size();
				ans = min(ans1, ans);
			}
			count1 = count3;
			count2 = count3;
			check.clear();
			for (int k = 0; k < s.size(); k++)
			{
				if (s[k] == c2)
				{
					ind2 = k;
					break;
				}
			}

			let = 0;
			for (int k = ind2; k < s.size(); k++)
			{
				if (let % 2 == 0 && s[k] == c2 && count1 != 0)
				{
					check += s[k];
					count1--; let++;
				}
				if (let % 2 != 0 && s[k] == c1 && count2 != 0)
				{
					check += s[k];
					count2--; let++;
				}

			}
			// cout << check << endl;

			ok = confirm(check);
			if (ok)
			{
				int ans1 = s.size() - check.size();
				ans = min(ans1, ans);
			}
		}

	}
	for (int i = 0; i <= 9; i++)
	{
		int check5 = s.size() - mp[i];
		ans = min(ans, check5);
	}
	cout << ans << endl;


}
int32_t main()
{
	REDBULL
	w
	solve();

	return 0;
}