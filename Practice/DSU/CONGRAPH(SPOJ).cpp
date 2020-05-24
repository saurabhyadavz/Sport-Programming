
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

/* Reference : https://www.spoj.com/problems/CONGRAPH/
   Approach: Disjoint set union

*/
#include <bits/stdc++.h>
using namespace std;

#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define endl "\n"
#define MAX 800000
int parent[MAX + 1];
int find(int a)

{
    if (a == parent[a]) return a;

    return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}
int32_t main()
{
    REDBULL
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        Union(a + 1, b + 1);
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == parent[i])
            count++;
    }
    cout << count - 1 << endl;
    return 0;
}