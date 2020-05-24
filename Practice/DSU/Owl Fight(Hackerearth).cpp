
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

/* Reference :https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/description/

   Approach: Disjoint set union

*/
#include <bits/stdc++.h>
using namespace std;

#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define endl "\n"
#define MAX 100000
int parent[MAX + 1];
int find(int a)

{
    if (parent[a] < 0) return a;

    return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    parent[a] = min(parent[a], parent[b]);
    parent[b] = a;
}
int32_t main()
{
    REDBULL
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = -i;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b))
            Union(find(a), find(b));
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
            cout << "TIE" << endl;
        else {
            int a1 = find(a);
            int a2 = find(b);
            if (abs(parent[a1]) > abs(parent[a2]))
                cout << a << endl;
            else
                cout << b << endl;
        }
    }
    return 0;
}