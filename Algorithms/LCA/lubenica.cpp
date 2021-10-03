/*
https://vn.spoj.com/problems/LUBENICA/en/
summary: find the max, min edge on the path between two nodes in the tree

*/
#include <bits/stdc++.h>

/*
    findPar(u,v);
*/
using namespace std;
const int MAXN = 100005;

vector<pair<int, int>> adj[MAXN];  // (adjnode, weight)
bool visited[MAXN];
int n, lev;
int par[MAXN][20], minn[MAXN][20], maxx[MAXN][20];
int pow2[20];
int h[MAXN];

void input()
{
    scanf("%d", &n);
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
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
        for (pair<int, int> ad : adj[u]) {
            int v = ad.first;
            if(!visited[v]){
                h[v] = h[u] + 1;
                par[v][0] = u;
                minn[v][0] = ad.second;
                maxx[v][0] = ad.second;
                myque.push(v);
            }
        }
    }

}

void initLCA()
{
    bfs(1);
    lev = trunc(log(n) / log(2)) + 1;
    for (int i = 1; i <= lev; i++)
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
            minn[j][i] = min(minn[par[j][i - 1]][i - 1], minn[j][i - 1]);
            maxx[j][i] = max(maxx[par[j][i - 1]][i - 1], maxx[j][i - 1]);
        }

    pow2[0] = 1;
    for (int i = 1; i <= lev; i++)
        pow2[i] = pow2[i - 1] * 2;
}

int jump(int u, int l, pair<int, int>& res)
{
    int v = u;

    for (int i = lev; i >= 0; i--)
        if (l >= pow2[i])
        {
            res.first = min(res.first, minn[v][i]);
            res.second = max(res.second, maxx[v][i]);
            v = par[v][i];
            l = l - pow2[i];
        }
    return v;
}
pair<int, int> findPar(int u, int v)  //min, max
{
    // cout << u <<" "<<v<<endl;
    pair<int, int> res = {INT_MAX, INT_MIN};
    if (h[u] > h[v])
        u = jump(u, h[u] - h[v], res);
    else
        v = jump(v, h[v] - h[u], res);
    // cout << u <<"*"<<v<<endl;
    if (u == v)
        return res;
    for (int i = lev; i >= 0; i--) {
        if (par[u][i] != par[v][i])
        {
            res.first = min({res.first, minn[v][i], minn[u][i]});
            res.second = max({res.second, maxx[v][i], maxx[u][i]});
            u = par[u][i];
            v = par[v][i];
        }
    }
    res.first = min({res.first, minn[u][0], minn[v][0]});
    res.second = max({res.second, maxx[u][0], maxx[v][0]});
    return res;
}
void init()
{
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    initLCA();
    int q;
    scanf("%d", &q);
    int u, v;
    for(int t = 0; t < q; t++) {
        scanf("%d%d", &u, &v);
        auto res = findPar(u, v);
        printf("%d %d\n", res.first, res.second);
    }
}

int main()
{
    //freopen("code.in","r",stdin);
    input();
    init();
    // solve();
}
