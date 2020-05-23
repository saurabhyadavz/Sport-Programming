
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
#define MAX 1000001
int tree[4 * MAX + 10];
int arr[MAX];


void build(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = arr[s];
        return ;
    }
    build(2 * node, s, (s + e) / 2);
    build(2 * node + 1, 1 + (s + e) / 2, e);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int s, int e, int index, int value)
{
    if (s == e)
    {
        tree[node] += value;
        return;
    }
    if (index <= (s + e) / 2)
        update(2 * node, s, (s + e) / 2, index, value);
    else
        update(2 * node + 1, 1 + (s + e) / 2, e, index, value);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int s, int e, int l, int r)
{
    if (s > r || e < l)
        return 0;
    if (s >= l && e <= r)
        return tree[node];

    return (query(2 * node, s, (s + e) / 2, l, r) + query(2 * node + 1, 1 + (s + e) / 2, e, l, r));
}



int32_t main()
{
    REDBULL
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'q')
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << endl;

        }
        else
        {
            int index, value;
            cin >> index >> value;
            update(1, 0, n - 1, index - 1, value);
        }
    }



    return 0;
}