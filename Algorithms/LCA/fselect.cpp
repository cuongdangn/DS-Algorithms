#include <bits/stdc++.h>

/*
    findPar(u,v);
*/
using namespace std;
const int MAXN = 200005;

vector<int> adj[MAXN];
vector<int> meeting[MAXN];
bool visited[MAXN];
int n, lev, k;
int par[MAXN][20];
int pow2[20];
int h[MAXN];
int root;

void input()
{
    scanf("%d%d", &n, &k);
    int u, v;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &u, &v);
        if(v != 0)
            adj[v].push_back(i);
        else
            root = i;
        meeting[u].push_back(i);
        
    }
}

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
    bfs(root);
    initLCA();

    for(int i = 1; i <= k; i++) {
        int n1 = meeting[i].size();
        int t = 0;
        int res = 0;
        int res1 = t;

        for(int j = 1; j < n1; j++) {
            int u = meeting[i][t];
            int v = meeting[i][j];
            int p = findPar(u, v);
            //cout << u << " " << v << " " << p << endl;
            if(res < h[u] + h[v] - 2*h[p]) {
                res = h[u] + h[v] - 2*h[p];
                res1 = j;
            }
        }

        res = 0;
        t = res1;
        for(int j = 0; j < n1; j++) 
        if(t != j) {
            int u = meeting[i][t];
            int v = meeting[i][j];
            int p = findPar(u, v);
            if(res < h[u] + h[v] - 2*h[p]) {
                res = h[u] + h[v] - 2*h[p];
            }
        }

        printf("%d\n", res);
    }
}

int main()
{
    //freopen("code.in","r",stdin);
    input();
    init();
    // solve();
}
