#include <bits/stdc++.h>

/*
    findPar(u,v);
*/
using namespace std;
const int MAXN = 100005;

vector<int> ke[MAXN];
bool visit[MAXN];
int n,lev;
int cha[MAXN][20];
int lt2[20];
int h[MAXN];

void input()
{
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d",&u);
        ke[i+1].push_back(u);
        ke[u].push_back(i+1);
    }

}
void dfs(int x)
{
    visit[x] = true;
    int siz = ke[x].size();
    for(int i=0;i<siz;i++)
    if(!visit[ke[x][i]]){
        cha[ke[x][i]][0] = x;
        h[ke[x][i]]=h[x]+1;
        dfs(ke[x][i]);
    }
}
void initLCA()
{
    lev = trunc(log(n)/log(2))+1;
    for(int i=1;i<=lev;i++)
        for(int j=1;j<=n;j++)
            cha[j][i] = cha[cha[j][i-1]][i-1];

    lt2[0] = 1;
    for(int i=1;i<=lev;i++)
        lt2[i] = lt2[i-1]*2;
}

int jump(int u,int l)
{
    int v = u;

    for(int i=lev;i>=0;i--)
    if(l>=lt2[i]){
        v = cha[v][i];
        l = l-lt2[i];
    }
    return v;
}
int findPar(int u,int v)
{
    // cout << u <<" "<<v<<endl;
    if(h[u]>h[v])
        u = jump(u,h[u]-h[v]);
    else
        v = jump(v,h[v]-h[u]);
   // cout << u <<"*"<<v<<endl;
    if(u==v)
        return u;
    for(int i=lev;i>=0;i--)
    if(cha[u][i]!=cha[v][i]){
        u = cha[u][i];
        v = cha[v][i];
    }
    return cha[u][0];
}
void init()
{
    for(int i=1;i<=n;i++)
        visit[i] = false;
    dfs(1);
    initLCA();
}

int main()
{
    //freopen("code.in","r",stdin);
    input();
    init();
   // solve();
}
