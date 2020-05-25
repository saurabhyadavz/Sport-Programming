
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
#define log 20

int weight[MAX + 1];
int lca[MAX + 1][log];
int store[MAX + 1][log];
int level[MAX + 1];
vector<int> graph[MAX + 1];


void dfs(int node, int parent, int h)
{
    lca[node][0] = parent;
    level[node] = h;
    if (parent != -1)
    {
        store[node][0] = weight[node] ^ weight[parent];
    }
    for (int i = 1; i < log; i++)
    {
        if (lca[node][i - 1] != -1)
        {
            lca[node][i] = lca[lca[node][i - 1]][i - 1];
            store[node][i] = (store[node][i - 1]) ^ (store[lca[node][i - 1]][i - 1]) ^ (weight[lca[node][i - 1]]);
        }
    }

    for (int i : graph[node])
    {
        if (i == parent)
            continue;
        dfs(i, node, h + 1);
    }
}

int  LCA(int u, int v)
{
    if (level[u] > level[v])
        swap(u, v);
    for (int i = log - 1; i >= 0; i--)
    {
        if (lca[v][i] != -1 && level[lca[v][i]] >= level[u])
        {
            v = lca[v][i];
        }
    }
    if (v == u)
    {
        return v;
    }

    for (int i = log - 1; i >= 0; i--)
    {
        if (lca[v][i] != lca[u][i]) {

            v = lca[v][i];
            u = lca[u][i];
        }
    }
    return lca[u][0];
}

void findxor(int u, int v)
{
    int lca1 = LCA(u, v);
    // cout << lca1 << endl;
    // cout << "here" << endl;
    int d1 = level[u] - level[lca1];
    int d2 = level[v] - level[lca1];
    int xor1 = 0;
    // cout << d1 << endl;
    // cout << d2 << endl;
    int temp = 0;
    if ((d1 == 0 && d2 != 0) || (d1 != 0 && d2 == 0))
        temp = 1;
    while (d1 != 0)
    {

        int check = log2(d1);
        int find = pow(2, check);
        xor1 ^= store[u][check];
        d1 -= find;
        u = lca[u][check];
        if (d1 != 0)
        {
            xor1 ^= weight[u];
        }
    }

    while (d2 != 0)
    {
        int check = log2(d2);
        // cout << d2 << endl;
        int find = pow(2, check);
        xor1 ^= store[v][check];
        d2 -= find;
        v = lca[v][check];
        if (d2 != 0)
        {
            xor1 ^= weight[v];
        }
    }
    if (temp == 0)
        xor1 ^= weight[lca1];
    cout << xor1 << endl;

}

int32_t main()
{
    REDBULL


    w() {
        int n, q;
        cin >> n >> q;
        loop(i, 1, n + 1)
        {
            cin >> weight[i];
            graph[i].clear();
        }
        loop(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        loop(i, 1, n + 1)
        {
            loop(j, 0, log)
            {
                lca[i][j] = -1;
                store[i][j] = -1;
            }
        }

        dfs(1, -1, 0);
        while (q--)
        {
            int u, v; cin >> u >> v;
            findxor(u, v);
        }
    }




    return 0;
}