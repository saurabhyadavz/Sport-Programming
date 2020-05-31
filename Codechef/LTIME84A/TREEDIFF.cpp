#include<bits/stdc++.h>
using namespace std;

#define log 24
#define int long long int
#define endl "\n"
#define MAX 300000
int level[300000];
int lca[300000][log];

vector<int> graph[300000];

void dfs(int node, int parent, int h)
{
    level[node] = h;
    lca[node][0] = parent;

    for (int i = 1; i < log; i++ )
    {
        if (lca[node][i - 1] != -1)
        {
            lca[node][i] = lca[lca[node][i - 1]][i - 1];
        }
    }

    for (int child : graph[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, h + 1);
    }


}
int LCA(int u, int v)
{

    if (level[u] > level[v])
        swap(u, v);

    for (int i = log - 1 ; i >= 0; i--)
    {

        if (lca[v][i] != -1 && level[lca[v][i]] >= level[u])
        {

            v = lca[v][i];
        }
    }
    if (v == u)
    {
        return v;
    }
    else
    {
        for (int i = log - 1; i >= 0; i--)
        {
            if (lca[u][i] != lca[v][i])
            {

                v = lca[v][i];
                u = lca[u][i];
            }
        }
        return lca[u][0];
    }

}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    // cout << log2(200000) << endl;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int weight[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i];
            graph[i].clear();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < log; j++)
            {
                lca[i][j] = -1;
            }
        }
        dfs(1, -1, 0);

        while (q--)
        {
            int u, v;
            cin >> u >> v;
            int lca1 = LCA(u, v);
            vector<int> ans;
            int dist = level[u] + level[v] - 2 * level[lca1];
            if (dist > 100)
            {
                cout << 0 << endl;
            }
            else
            {
                while (u != lca1)
                {
                    ans.push_back(u);
                    u = lca[u][0];
                }
                while (v != lca1)
                {
                    ans.push_back(v);
                    v = lca[v][0];
                }
                ans.push_back(lca1);
                sort(ans.begin(), ans.end());
                vector<int> ans1;
                for (int i = 0; i < ans.size(); i++)
                {
                    // cout << ans[i] << " ";

                    ans1.push_back(weight[ans[i]]);
                }
                // cout << endl;
                sort(ans1.begin(), ans1.end());
                int diff = ans1[ans1.size() - 1] - ans1[0];
                for (int i = 0; i < ans1.size() - 1; i++)

                {
                    int temp = ans1[i + 1] - ans1[i];
                    if (temp < diff)
                        diff = temp;
                }

                cout << diff << endl;
            }

        }
    }


    return 0;
}