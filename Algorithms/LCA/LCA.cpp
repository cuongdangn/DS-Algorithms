#include <bits/stdc++.h>

/*
    findPar(u,v);
*/
using namespace std;
const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];
int n, lev;
int par[MAXN][20];
int pow2[20];
int h[MAXN];

void input()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &u);
        adj[i + 1].push_back(u);
        adj[u].push_back(i + 1);
    }
}
// void dfs(int x)
// {
//     visited[x] = true;
//     int siz = adj[x].size();
//     for (int i = 0; i < siz; i++)
//         if (!visited[adj[x][i]])
//         {
//             par[adj[x][i]][0] = x;
//             h[adj[x][i]] = h[x] + 1;
//             dfs(adj[x][i]);
//         }
// }

void bfs(int x)
{
    queue<int> myque;

    myque.push(x);

    while(!myque.empty()) {
        int u = myque.front();
        myque.pop();
        visited[u] = true;
        for (int v : adj[u]) 
            if(!visited[v]){
                h[v] = h[u] + 1;
                par[v][0] = u;
                myque.push(v);
            }
    }

}

void initLCA()
{
    lev = trunc(log(n) / log(2)) + 1;
    for (int i = 1; i <= lev; i++)
        for (int j = 1; j <= n; j++)
            par[j][i] = par[par[j][i - 1]][i - 1];

    pow2[0] = 1;
    for (int i = 1; i <= lev; i++)
        pow2[i] = pow2[i - 1] * 2;
}

int jump(int u, int l)
{
    int v = u;

    for (int i = lev; i >= 0; i--)
        if (l >= pow2[i])
        {
            v = par[v][i];
            l = l - pow2[i];
        }
    return v;
}
int findPar(int u, int v)
{
    // cout << u <<" "<<v<<endl;
    if (h[u] > h[v])
        u = jump(u, h[u] - h[v]);
    else
        v = jump(v, h[v] - h[u]);
    // cout << u <<"*"<<v<<endl;
    if (u == v)
        return u;
    for (int i = lev; i >= 0; i--)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
void init()
{
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    bfs(1);
    initLCA();
}

int main()
{
    //freopen("code.in","r",stdin);
    input();
    init();
    // solve();
}
