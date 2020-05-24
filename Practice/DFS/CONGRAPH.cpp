
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

/* Reference :https://www.spoj.com/problems/FENTREE/
   Approach: Segment tree

*/
#include <bits/stdc++.h>
using namespace std;

#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define endl "\n"
#define MAX 800001

vector<int> graph[MAX];
bool visited[MAX];
void dfs(int i)
{
    visited[i] = true;
    for (int child : graph[i])
    {
        if (visited[child])
            continue;
        dfs(child);
    }
}
void check(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            count++;
            dfs(i);
        }
    }
    cout << count - 1 << endl;
}

int32_t main()
{
    REDBULL
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    check(n);
    return 0;
}