
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

struct Query {

    int L;
    int R;
    int index;

};

int arr[1000001];
int ans[200001];
int blk_sz = 600;
int freq[1000001];
int let;

bool compare(Query x, Query y)
{
    if (x.L / blk_sz != y.L / blk_sz)
        return x.L / blk_sz < y.L / blk_sz;

    return x.R < y.R;
}
void add(int a) {

    freq[arr[a]]++;
    if (freq[arr[a]] == 1)
    {
        let++;
    }

}
void remove(int a) {

    freq[arr[a]]--;
    if (freq[arr[a]] == 0)
        let--;
}

int32_t main()
{

    REDBULL

    int n;
    cin >> n;

    loop(i, 1, n + 1)
    cin >> arr[i];

    int q;
    cin >> q;

    Query qq[q];
    loop(i, 0, q)
    {
        int l, r;
        cin >> l >> r;
        qq[i].L = min(l, r);
        qq[i].R = max(l, r);
        qq[i].index = i;


    }


    sort(qq, qq + q, compare);
    int currL = 0, currR = 0;
    let = 0;
    loop(i, 0, q) {


        int L = qq[i].L , R = qq[i].R ;


        while (currR < R) {

            currR++;
            add(currR);
        }
        while (currL > L) {

            currL--;
            add(currL);
        }


        while (currR > R )

        {
            remove(currR);
            currR--;
        }
        while (currL < L) {
            remove(currL);
            currL++;
        }




        ans[qq[i].index] = let;

    }
    loop(i, 0, q) {
        cout << ans[i] << endl;
    }
    return 0;
}