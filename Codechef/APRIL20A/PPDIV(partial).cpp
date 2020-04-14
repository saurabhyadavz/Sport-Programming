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

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return ((int)x.first)^(((int)x.second)<<32);
  }
};


vector<int> v;

void Divisors(int n) 
{ 
   
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                {
                        v.pb(i);
                     
                   
                }
  
            else{
                        v.pb(i);
                        v.pb(n/i);
            } 
        } 
    }


 
}
int32_t main()
{


  REDBULL
  
    int n=1000000000000;
    v.pb(1); 
    for (int i = 2; i * i <= n; i++) { 
        int j = i * i; 
        v.push_back(j); 
        while (j * i <= n) { 
            v.push_back(j * i); 
            j = j * i; 
        } 
    } 
  
    sort(v.begin(), v.end()); 
    v.erase(unique(v.begin(), v.end()), v.end()); 
  
    w()
    {
        int x;
        cin>>x;
        int ans=0;
        auto check=lower_bound(v.begin(), v.end(),x);
        int len=check-v.begin();
        for(int i=0;i<=len;i++)
        {
            int div=x/v[i];
            int le=(div%mod*v[i]%mod)%mod;
            ans=(ans%mod+le%mod)%mod;
        }
        cout<<ans<<endl;
        
    }


 return 0;
}