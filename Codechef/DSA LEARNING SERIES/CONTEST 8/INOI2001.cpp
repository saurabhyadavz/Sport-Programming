
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


vector<int> graph[MAX + 1];
int visited[MAX + 1];
int maxi, mini, siz;
int ans1, ans2;
void dfs(int node)
{
    // cout << "here" << endl;
    siz++;
    visited[node] = 1;
    maxi = max(maxi, node);
    mini = min(mini, node);
    for (int i : graph[node])
    {
        if (!visited[i])
            dfs(i);
    }
}

void dfs2(int node, int h)
{
    ans1 += h;
    visited[node] = 1;
    for (int i : graph[node])
    {
        if (!visited[i])
            dfs2(i, h + 1);
    }
}
void dfs3(int node, int h)
{
    ans2 += h;
    visited[node] = 1;
    for (int i : graph[node])
    {
        if (!visited[i])
            dfs3(i, h + 1);
    }
}
int32_t main()
{
    // REDBULL


    w()
    {
        int n, m;
        cin >> n >> m;

        loop(i, 1, n + 1)
        {
            graph[i].clear();
            visited[i] = 0;
        }

        loop(i, 0, m)
        {
            int u, v; cin >> u >> v;
            graph[v].pb(u);
            graph[u].pb(v);
        }
        vector<int> even, odd;
        loop(i, 1, n + 1)
        {
            if (!visited[i])
            {
                maxi = INT_MIN;
                mini = INT_MAX;
                siz = 0;
                dfs(i);
                if (siz % 2 == 0)
                    even.pb(mini);
                else
                    odd.pb(maxi);
            }
        }

        loop(i, 1, n + 1)
        visited[i] = 0;
        ans1 = 0; ans2 = 0;
        loop(i, 0, even.size())
        {
            dfs2(even[i], 1);
        }
        loop(i, 0, odd.size())
        {
            dfs3(odd[i], 1);
        }
        cout << ans1 << " " << ans2 << endl;
    }




    return 0;
}