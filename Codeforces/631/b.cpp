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
  w(){
    int n;
    cin>>n;
    int a[n];
    loop(i,0,n)
    cin>>a[i];
    int left[n]={0};
    int right[n]={0};
    set<int> set1,set2;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        set1.insert(a[i]);
        int max1=(*set1.rbegin());
        int min1=(*set1.begin());
        if(min1==1&&max1==i+1&&set1.size()==i+1)
            left[i]=1;

    }

   
    sum=0;
    int j=0;
    for(int i=n-1;i>=0;i--){
        j++;
        set2.insert(a[i]);
        int max1=(*set2.rbegin());
        int min1=(*set2.begin());
        if(min1==1&&max1==j&&set2.size()==j)
            right[i]=1;
    }
  
   
  
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(left[i]==1&&i!=n-1){
            if(right[i+1]==1){
                count++;
                
            }
        }
    }
    cout<<count<<endl;
    for(int i=0;i<n;i++)
    {
        if(left[i]==1&&i!=n-1){
            if(right[i+1]==1){
                cout<<i+1<<" "<<n-i-1<<endl;
               
            }
        }
    }

   
  }

 return 0;
}