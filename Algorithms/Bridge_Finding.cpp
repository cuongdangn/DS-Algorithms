#include <bits/stdc++.h>

using namespace std;

#define maxn 10002
#define maxm 50002

typedef pair<int, int> ii;

int child[maxn], par[maxn], low[maxn], num[maxn];
bool visited[maxm], dd[maxn];
int n, m, dem, kq1, kq2;
vector<ii> adj[maxn];

void doc()
{
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(ii(v, i));
        adj[v].push_back(ii(u, i));
    }
}
void dfs(int u)
{
    dem++;
    num[u] = dem;
    low[u] = maxn;
    int l = adj[u].size();
    for (int i = 0; i < l; i++)
    {
        int v = adj[u][i].first;
        int c = adj[u][i].second;
        if (visited[c])
        {
            visited[c] = false;
            if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else
            {
                par[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
}
void timkhop()
{
    int u;
    for (int i = 1; i <= m; i++)
        visited[i] = true;
    for (int i = 1; i <= n; i++)
        dd[i] = false;

    for (int i = 1; i <= n; i++)
        if (num[i] == 0)
        {
            dfs(i);
            par[i] = -1;
        }
    for (int i = 1; i <= n; i++)
        if (par[i] != -1)
            if (low[i] >= num[i])
                kq2++; // cac canh noi tu i den cha cua no la cau
    ///////////////////////////////
    for (int i = 1; i <= n; i++)
    {
        u = par[i];
        if (u != -1 && par[u] != -1)
            if (low[i] >= num[u])
                dd[u] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        u = par[i];
        if (u > 0)
            child[u]++;
    }
    for (int i = 1; i <= n; i++)
        if (child[i] > 1 && par[i] == -1)
            dd[i] = true;

    for (int i = 1; i <= n; i++)
        if (dd[i]) // dd[i] = true thi i l� khop
            kq1++;
    printf("%d %d", kq1, kq2);
    //kq1=khop kq2=cau
}
int main()
{
    doc();
    timkhop();
}
