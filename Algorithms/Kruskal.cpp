/*
    mst ~
*/
#include <bits/stdc++.h>

#define ii pair<int, int>
#define li pair<long long, int>
#define il pair<int, long long>
#define oo_i INT_MAX
#define oo_l 100000000000000000
#define bug(i) cout << i <<endl;

using namespace std;

struct Node {
    int u,v,w;
    bool operator<(const Node& rhs)const{
        return w<rhs.w;
    }
    Node(int u1,int v1,int w1){
        u=u1;
        v=v1;
        w=w1;
    }
    Node(){
        u=0;v=0;w=0;
    }
};
const int MAXM = 100005;
const int MAXN = 100002;
Node lis[MAXM];
int n,m;
int heigh[MAXN];
int pa[MAXN];

void input()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        lis[i] = Node(u,v,w);
    }
}
int findroot(int x)
{
    if(pa[x]==x) return x;
    pa[x] = findroot(pa[x]);
    return pa[x];
}
void kruskal()
{
    int mst = 0;
    sort(lis+1,lis +m+1);
    for(int i=1;i<=n;i++)
        pa[i] = i;
    for(int i=1;i<=m;i++){
        int p1 = findroot(lis[i].u);
        int p2 = findroot(lis[i].v);
        if(p1!=p2){
            mst = mst + lis[i].w;
            if(heigh[p1]>heigh[p2]){
                pa[p2] = p1;
            }
             if(heigh[p1]<heigh[p2]){
                pa[p1] = p2;
            }
             if(heigh[p1]==heigh[p2]){
                pa[p2] = p1;
                heigh[p1]++;
            }
        }
    }
    cout << mst;
}
int main()
{
    input();
    kruskal();
}
