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

int32_t main()
{

 REDBULL
  
 int u,v;
 cin>>u>>v;

 if((u%2==0&&v%2!=0)||(u>v)||(u%2!=0&&v%2==0))
 {
 	cout<<-1<<endl;
 	return 0;
 }
 if(v>=u)
 {
 	if(u==v)
 	{
 		 if(u==0)
 		 	cout<<0<<endl;
 		 else{
 		 	cout<<1<<endl;
 		 	cout<<u<<endl;
 		 }
 	}
 	else{
 		int n=(v-u)/2;
 		if(n&u){
 			cout<<3<<endl;
 			cout<<u<<" "<<n<<" "<<n<<endl;

 		}
 		else
 		{
 			cout<<2<<endl;
 			cout<<(u^n)<<" "<<n<<endl;
 		}
 	}
 }
 

 return 0;
}