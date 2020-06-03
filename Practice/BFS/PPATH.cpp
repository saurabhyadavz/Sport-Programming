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

vector<int> graph[10009];
bool prime[10009];
void SieveOfEratosthenes()
{


	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= 10000; p++)
	{
		if (prime[p] == true)
		{

			for (int i = p * p; i <= 10000; i += p)
				prime[i] = false;
		}
	}


}

void bfs(int source, int destination)
{

	int level[10009] = {};
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(source);
	level[source] = 0;

	while (q.size() != 0)
	{

		int top = q.front();
		q.pop();

		for (int j = 0; j < 4; j++)
		{
			string s1 = to_string(top);
			for (int k = 0; k <= 9; k++)
			{

				char c = '0' + k;
				s1[j] = c;
				int num = stoi(s1);
				if ( prime[num] && level[num] == -1 && num > 1000)
				{

					level[num] = level[top] + 1;
					q.push(num);

				}
				// cout << num << endl;
				// }
			}
		}


	}
	if (level[destination] == -1)
		cout << "Impossible" << endl;
	else
		cout << level[destination] << endl;


}
int32_t main()
{
	REDBULL

	SieveOfEratosthenes();

	w{
		int a, b;
		cin >> a >> b;

		if (a == b)
		{
			cout << 0 << endl; continue;
		}
		bfs(a, b);


	}

	return 0;
}