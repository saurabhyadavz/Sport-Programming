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
#define MAX 1000045 
#define bitscount 32 
#define make(x,y) make_pair(x,y)
#define LOAD_FACTOR_set(name) name.reserve(32768);name.max_load_factor(0.25);
#define LOAD_FACTOR_map(name) name.reserve(1024);name.max_load_factor(0.25);
#define lcm(a,b) ((a*b))/(__gcd(a,b))
#define int long  int
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

int prime[MAX]; 
int store[1004][1004];
void sieve() 
{ 
    memset(prime, 0, sizeof(prime)); 
    prime[0] = prime[1] = 1; 
    for (int i = 2; i * i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (int j = i * 2; j < MAX; j += i) { 
                if (prime[j] == 0) 
                    prime[j] = i; 
            } 
        } 
    } 
    for (int i = 2; i < MAX; i++) { 
        if (prime[i] == 0) 
            prime[i] = i; 
    } 
} 

void addEdge(vector<int> v[], int x, int y) 
{ 
    v[x].push_back(y); 
    v[y].push_back(x); 
} 

void DFS(vector<int> v[], bool vis[], int x, int y, vector<int> stack,int arr[],unordered_map<int,int> mp) 
{ 
    stack.push_back(x);
    if(stack.size()==0)
        return; 
    if (stack.size()!=0) 
    { 
            int n=stack.size();
            int temp=arr[stack[n-1]-1];
            while (temp != 1) {

                mp[prime[temp]]++; 
                temp = temp / prime[temp]; 
             }
             int ans = 1;    
            fore(mp){
                ans = (ans%mod * (it->second + 1)%mod)%mod; 
            }

            // cout<<y<<" "<<x<<"->"<<ans<<endl;

            store[x][y]=ans;
            store[y][x]=ans;

    } 
    vis[x] = true; 
  
    int flag = 0; 
    if (!v[x].empty()) { 
        for (int j = 0; j < v[x].size(); j++) { 
            if (vis[v[x][j]] == false) { 
                DFS(v, vis, v[x][j], y, stack,arr,mp); 
                flag = 1; 
            } 
        } 
    } 
    if (flag == 0) {
        int temp=arr[stack[stack.size()-1]-1];
        while(temp!=1){
            mp[prime[temp]]--;
            if(mp[prime[temp]]==0)
                mp.erase(prime[temp]);
            temp = temp / prime[temp]; 
        }

        stack.pop_back(); 
    } 
} 

void DFSCall(int x, int y, vector<int> v[], int n, vector<int> stack,int arr[]) 
{ 
   
    bool vis[n + 1]; 
    memset(vis, false, sizeof(vis));
    unordered_map<int,int> mp; 
    DFS(v, vis, x, y, stack,arr,mp); 
}
int32_t main()
{


    REDBULL
    sieve(); 
    int t; cin>>t; 
    for(int i=0; i<t; i++)
    {
       
        int n;
        cin>>n;
        assert(n<=1000);
        vector<int> v[n+1];
        for(int i=0;i<n-1;i++)
        {
            int x1,x2;
            cin>>x1>>x2;
            addEdge(v,x1,x2);
        }
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=1;i<=1001;i++)
            for(int j=1;j<=1001;j++)
                store[i][j]=0;
        
        for(int i=1;i<=n;i++){
            vector<int> stack;
            DFSCall(i,i,v,n,stack,arr);
        }
       
        int q;
        cin>>q;
        while(q--)
        {
            int u1,v1;
            cin>>u1>>v1;
            cout<<store[u1][v1]<<endl;
        }
    }
    
 return 0;
}