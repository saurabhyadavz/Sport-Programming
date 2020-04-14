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
  
	w()
    {
		int n;
        cin>>n;
        int a[n];
        vector<int> v1,v2;
        loop(i,0,n)
        {
             cin>>a[i];
             if(a[i]%2==0)
                v1.pb(i);
             if(a[i]%4==0)
                v2.pb(i);
        }
        int ans=0;
        int temp=0;
        loop(i,0,n)

        {

            if(a[i]%4==0)
            {
                temp=0;
                ans+=(n-i);
                continue;
            }
            if(a[i]%2==0){
                temp=0;
                auto check=upper_bound(v1.begin(), v1.end(),i);
                if(check!=v1.end())
                {
                    int ind=*check;
                    if((n-ind)>0)
                        ans+=(n-ind);
                }
               
            }
            else{
                temp++;
                ans+=temp;
                int min1=INT_MAX;
                int min2=INT_MAX;
                auto check=upper_bound(v1.begin(), v1.end(),i);

                if(check!=v1.end())
                {
                     check++;
                     if(check!=v1.end())
                     {
                        int ind=*check;
                         if(ind<n)
                            min1=ind;
                     }
                                     
                }
               auto check2=upper_bound(v2.begin(), v2.end(),i);
               if(check2!=v2.end())
               {
                    int ind=*check2;
                    if(ind<n)
                        min2=ind;
               }
           
               int le=min(min2,min1);
               if((n-le)>0)
                ans+=(n-le);
            }
        }   

        cout<<ans<<endl;
        

	}


 return 0;
}