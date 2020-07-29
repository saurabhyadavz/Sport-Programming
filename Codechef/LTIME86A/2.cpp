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


int32_t main()
{
	REDBULL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++)
	{
		int n;
		cin >> n;
		string in, out;
		cin >> in >> out;
		char ans[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					ans[i][i] = 'Y';
			}

		for (int i = 0; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (abs(i - j) == 1)
				{
					if (out[i] == 'Y' && in[j] == 'Y')
						ans[i][j] = 'Y';
					else
						ans[i][j] = 'N';
				}
				else {
					int start = j + 1;
					int end = j;
					if (out[start] == 'Y' && in[end] == 'Y')
						ans[start][end] = 'Y';
					else
						ans[start][end] = 'N';
					if (ans[start][end] == 'Y')
					{
						int temp = 0;
						for (int k = j + 1; k < i; k++)
						{
							if (ans[i][k] != 'Y')
							{
								temp = 1; break;
							}
						}
						if (temp)
							ans[i][j] = 'N';
						else
							ans[i][j] = 'Y';
					}
					else
						ans[i][j] = 'N';
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					ans[i][j] = 'Y';
				}
				else if (abs(j - i) == 1) {
					if (out[i] == 'Y' && in[j] == 'Y')
						ans[i][j] = 'Y';
					else
						ans[i][j] = 'N';
				}
				else if (j > i && abs(j - i) != 1)
				{
					int start = j - 1;
					int end = j;

					if (out[start] == 'Y' && in[end] == 'Y')
						ans[start][end] = 'Y';
					else
						ans[start][end] = 'N';
					if (ans[start][end] == 'Y')
					{
						int temp = 0;
						for (int k = i; k < j; k++)
						{
							if (ans[i][k] != 'Y')
							{
								temp = 1;
								break;
							}
						}
						if (temp)
							ans[i][j] = 'N';
						else
							ans[i][j] = 'Y';
					}
					else {
						ans[i][j] = 'N';
					}

				}
			}
		}
		cout << "Case #" << t1 << ":" << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << ans[i][j];
			cout << endl;
		}
	}


	return 0;
}


