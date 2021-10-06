/*
    https://vn.spoj.com/problems/QTREE3/
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define F first
#define S second
#define PB push_back

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

const int MAXN = 100005;

int n, q;
vector<int> adj[MAXN];
int parent[MAXN];
int nChild[MAXN];

// chainHead[i] = head of chain with index i
// chainInd[i] = index of chain that i belong
// posInBase[i] = position of i in the chain
int chainHead[MAXN], chainInd[MAXN], posInBase[MAXN];
int nChain, nBase;

//
set<pair<int, int>> ms[MAXN];
int color[MAXN];

void input() {
    cin >> n >> q;
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p)
{
    for(int v : adj[u]) {
        if(v != p) {
            parent[v] = u;
            dfs(v, u);
            nChild[u] += nChild[v];
        }
    }
    nChild[u]++;
}

void hld(int u)
{

    if (chainHead[nChain] == 0)
        chainHead[nChain] = u;

    chainInd[u] = nChain;

    posInBase[u] = ++nBase;

    int mxVtx = -1;

    for(int v : adj[u]) {
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

    for(int v : adj[u]) {
        if (v != parent[u] && v != mxVtx)
        {
            nChain++;
            hld(v);
        }
    }
}

void query(int u) {
    int res = -1;
    while(u != 0) {
        if(!ms[chainInd[u]].empty()) {
            int t = (*ms[chainInd[u]].begin()).second;
            if(posInBase[t] <= posInBase[u]) {
                res = t;
            }
        }
        u = parent[chainHead[chainInd[u]]];
    }
    cout << res << endl;
}

void updateColor(int u) {
    color[u] = 1 - color[u];
    if(color[u] == 1) {
        ms[chainInd[u]].insert({posInBase[u], u});
    } else {
        ms[chainInd[u]].erase({posInBase[u], u});
    }
}

void solve() {
    dfs(1, 0);
    hld(1);
    int t, u;
    for(int i = 0; i < q; i++) {
        cin >> t >> u;
        if(t == 0) {
            updateColor(u);
        } else {
            query(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("code.in", "r", stdin);
        freopen("code.ou", "w", stdout);
    #endif

    input();
    solve();

    return 0;

}
