//http://vn.spoj.com/problems/LCA/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
struct egde
{
    int u, v;
    int w;
};

vector<int> adj[N];
int parent[N];
int nChild[N];
int chainHead[N], chainInd[N], posInBase[N];
int n, nChain, nBase;

void input()
{
    scanf("%d", &n);
    int u, v, m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        adj[i].clear();
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &u);
            adj[i].push_back(u);
        }
    }
}
void dfs(int a)
{
    int m = adj[a].size();
    for (int i = 0; i < m; i++)
    {
        int u = adj[a][i];
        if (parent[u] == 0)
        {
            parent[u] = a;
            dfs(u);
            nChild[a] += nChild[u];
        }
    }
    nChild[a]++;
}
void hld(int u)
{

    if (chainHead[nChain] == 0)
        chainHead[nChain] = u;

    chainInd[u] = nChain;

    posInBase[u] = ++nBase;

    int mxVtx = -1;

    int m = adj[u].size();
    for (int i = 0; i < m; i++)
    {
        int v = adj[u][i];
        if (v != parent[u])
        {
            if (mxVtx == -1 || nChild[v] > nChild[mxVtx])
            {
                mxVtx = v;
            }
        }
    }

    if (mxVtx > -1)
        hld(mxVtx);

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v != parent[u] && v != mxVtx)
        {
            nChain++;
            hld(v);
        }
    }
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = 0;
        nChild[i] = 0;
        posInBase[i] = 0;
        chainHead[i] = 0;
    }
    parent[1] = -1;
    nChain = 0;
    nBase = 0;
    dfs(1);
    hld(1); // heavy light Decomposition
}
int LCA(int u, int v)
{
    while (chainInd[u] != chainInd[v])
    {
        if (posInBase[u] < posInBase[v])
            v = parent[chainHead[chainInd[v]]];
        else
            u = parent[chainHead[chainInd[u]]];
    }
    if (posInBase[u] > posInBase[v])
        return v;
    return u;
}
void solve()
{
    init();
    int q, u, v;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
}
int main()
{
    //freopen("code.in","r",stdin);
    int testCase;
    scanf("%d", &testCase);
    for (int i = 1; i <= testCase; i++)
    {
        printf("Case %d:\n", i);
        input();
        solve();
    }
}
