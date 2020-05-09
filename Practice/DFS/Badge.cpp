
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
// Question link:https://codeforces.com/problemset/problem/1020/B

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
#define MAX 100000
#define bitscount 32
#define make(x,y) make_pair(x,y)
#define LOAD_FACTOR_set(name) name.reserve(32768);name.max_load_factor(0.25);
#define LOAD_FACTOR_map(name) name.reserve(1024);name.max_load_factor(0.25);
#define lcm(a,b) ((a*b))/(__gcd(a,b))
#define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"

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
vector<int> v1[200001];
int color[200001];
int visited[200001];
bool bipartite(int u, int c) {

    visited[u] = 1;
    color[u] = c;
    for (int child : v1[u]) {
        if (visited[child] == 0) {
            bool check = bipartite(child, c ^ 1);
            if (check == false)
                return false;
        }


        else {

            if (color[child] == color[u])
                return false;
        }
    }

    return true;

}
int32_t main()
{

    REDBULL

    int n;
    cin >> n;
    int a[n + 1];
    loop(i, 1, n + 1)
    cin >> a[i];

    vector<int> ans;
    loop(i, 1, n + 1) {
        unordered_map<int, int, custom_hash> mp;
        unordered_map<int, int, custom_hash> visit;
        mp[i]++;
        visit[i] = 1;
        // cout << i << "->" << endl;
        int count = 0;
        int here = i, check;


        while (true) {
            check = a[here];
            // cout << check << endl;
            if (visit[check] == 0) {
                // cout << "ansd" << endl;
                visit[check] = 1;
                mp[check]++;
                here = check;
            }

            else
            {
                mp[check]++;
                break;
            }
        }
        // cout << i << "here " << endl;

        fore(mp) {
            if ((it->second) == 2) {
                ans.pb((it->first));
                // cout << (it->first) << endl;
            }
        }
    }
    for (int i : ans)
        cout << i << " ";
    cout << endl;


    return 0;
}