
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
#define MAX 1000


vector<set<int>> v(26);
int visited[26];
int temper;
void dfsjaisa(int from, int to)
{
    visited[from] = 1;
    for (auto it = v[from].begin(); it != v[from].end(); it++)
    {
        // cout << "here" << endl;
        if (*it == to)
        {
            temper = 1;
            return ;
        }
        if (visited[*it] == 0) {
            dfsjaisa(*it, to);
        }
    }

}
int32_t main()
{
    REDBULL

    w()
    {
        for (int i = 0; i < 26; i++)
        {
            v[i].clear();
        }
        string s, t;
        cin >> s >> t;
        int m;
        cin >> m;
        while (m--)
        {
            string s1;
            cin >> s1;
            char c1 = s1[0];
            char c2 = s1[3];
            v[c1 - 'a'].insert(c2 - 'a');
        }
        if (s.size() != t.size())
        {
            cout << "NO" << endl;
        }
        else
        {




            int not1 = 0;
            loop(i, 0, s.size())
            {
                if (s[i] != t[i])
                {
                    memset(visited, 0, sizeof visited);
                    temper = 0;
                    dfsjaisa(s[i] - 'a', t[i] - 'a');
                    if (!temper)
                    {
                        not1 = 1;
                        break;
                    }
                }
            }
            if (not1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;

        }
    }



    return 0;
}