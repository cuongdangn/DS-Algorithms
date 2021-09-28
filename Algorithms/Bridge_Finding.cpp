#include <bits/stdc++.h>

using namespace std;

#define maxn 10002
#define maxm 50002

typedef pair<int, int> ii;

int con[maxn],cha[maxn],low[maxn],num[maxn];
bool tham[maxm],dd[maxn];
int n,m,dem,kq1,kq2;
vector<ii> ke[maxn];

int doc()
{
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        ke[u].push_back(ii(v,i));
        ke[v].push_back(ii(u,i));
    }
}
int dfs(int u)
{
    dem++;
    num[u]=dem;
    low[u]=maxn;
    int l=ke[u].size();
    for(int i=0;i<l;i++){
        int v=ke[u][i].first;
        int c=ke[u][i].second;
        if(tham[c]){
            tham[c]=false;
            if(num[v]>0)low[u]=min(low[u],num[v]);
            else{
                cha[v]=u;
                dfs(v);
                low[u]=min(low[u],low[v]);
            }
        }
    }
}
int timkhop()
{
    int u;
    for(int i=1;i<=m;i++)tham[i]=true;
    for(int i=1;i<=n;i++)dd[i]=false;

    for(int i=1;i<=n;i++)
    if(num[i]==0){
        dfs(i);
        cha[i]=-1;
    }
    for(int i=1;i<=n;i++)
        if(cha[i]!=-1)
         if(low[i]>=num[i])kq2++; // cac canh noi tu i den cha cua no la cau
    ///////////////////////////////
    for(int i=1;i<=n;i++){
        u=cha[i];
        if(u!=-1&&cha[u]!=-1)
            if(low[i]>=num[u])dd[u]=true;
    }

    for(int i=1;i<=n;i++){
        u=cha[i];
        if(u>0)con[u]++;
    }
    for(int i=1;i<=n;i++)
        if(con[i]>1&&cha[i]==-1)dd[i]=true;

    for(int i=1;i<=n;i++)
        if(dd[i])  // dd[i] = true thi i là khop
            kq1++;
    printf("%d %d",kq1,kq2);
    //kq1=khop kq2=cau
}
int main()
{
    doc();
    timkhop();
}
