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

vector<int> adj[MAXN];
int parent[MAXN];
int nChild[MAXN];  // number of child

// chainHead[i] = head of chain with index i
// chainInd[i] = index of chain that i belong
// posInBase[i] = position of i in the chain
int chainHead[MAXN], chainInd[MAXN], posInBase[MAXN];
int n, nChain, nBase;

void input() {
    cin >> n;
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

int main() {
    dfs(1, 0);
    hld(1);
}