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
#define MAX 10000000000000

int findMaxGCD(int arr[], int n)
{
  // Calculating MAX in array
  int high = 0;
  for (int i = 0; i < n; i++)
    high = max(high, arr[i]);

  // Maintaining count array
  int count[high + 1] = {0};
  for (int i = 0; i < n; i++)
    count[arr[i]]++;

  // Variable to store the
  // multiples of a number
  int counter = 0;

  // Iterating from MAX to 1
  // GCD is always between
  // MAX and 1. The first
  // GCD found will be the
  // highest as we are
  // decrementing the potential
  // GCD
  for (int i = high; i >= 1; i--)
  {
    int j = i;
    counter = 0;

    // Iterating from current
    // potential GCD
    // till it is less than
    // MAX
    while (j <= high)
    {
      // A multiple found

      if (count[j] >= 2)
        return j;

      else if (count[j] == 1)
        counter++;

      // Incrementing potential
      // GCD by itself
      // To check i, 2i, 3i....
      j += i;

      // 2 multiples found,
      // max GCD found
      if (counter == 2)
        return i;
    }
  }
}
void solve()
{


  int n;
  cin >> n;
  int a[n];
  loop(i, 0, n)
  {
    a[i] = i + 1;
  }
  int max1 = findMaxGCD(a, n);
  cout << max1 << endl;
}
int32_t main()
{
  REDBULL
  w
  solve();

  return 0;
}