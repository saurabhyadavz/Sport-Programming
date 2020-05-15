
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
// #define MAX 100000

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


typedef pair< int, pair<int, int>> pi;

struct compare {
    bool operator()(pi const&p1, pi const&p2)
    {
        if (p1.first == p2.first)
            return p1.second.first > p2.second.first;
        else
            return p1.first < p2.first;
    }
};
int32_t main()
{

    REDBULL
    w()
    {
        int n;
        cin >> n;

        int arr[n + 1];
        int l = 1;
        int r = n;


        // set < pair<pair<int, int>, int>> set;
        priority_queue<pi, vector<pi>, compare> g;

        int count = 1;
        g.push(make_pair(r - l + 1, make_pair(l, r)));
        while (g.size() != 0)
        {
            pair<int, pair<int, int>> p1 = g.top();
            int mid ;
            int l1 = p1.second.first, r1 = p1.second.second;
            if ((r1 - l1 + 1) % 2 == 0)
            {
                mid = (l1 + r1 - 1) / 2;
            }
            else
            {
                mid = (l1 + r1 ) / 2;
            }
            arr[mid] = count;
            g.pop();
            count++;
            if (l1 <= mid - 1)
                g.push(make_pair(mid - l1, make_pair(l1, mid - 1)));
            if (mid + 1 <= r1)
                g.push(make_pair( r1 - mid, make_pair(mid + 1, r1)));
        }
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;



    }
    return 0;
}