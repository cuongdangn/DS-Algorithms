/*
    DQUERY
    find number of distinct elements in the subsequence
*/
#include <bits/stdc++.h>

using namespace std;

struct query{
    int l,r;
    int index;
};
const int MAXN = 30005;
int a[MAXN];
int n,q;
int sqrtn;
query qu[200005];
int coun[1000006];
int kqq[200006];

void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qu[i].l,&qu[i].r);
        qu[i].index = i;
    }


}
bool cmp(query a,query b)
{
    if(a.l/sqrtn != b.l/sqrtn){
        return a.l/sqrtn < b.l/sqrtn;
    }
    return a.r<b.r;
}
void init()
{
    sqrtn = trunc(sqrt(n));
    sort(qu+1,qu+q+1,cmp);

}
void solve()
{
    int l1,l2,r1,r2;
    int kq = 0;
    for(int i=qu[1].l;i<=qu[1].r;i++){
        coun[a[i]]++;
        if(coun[a[i]]==1)
            kq++;
    }
    kqq[qu[1].index] = kq;
    for(int i=2;i<=q;i++){
        l2 = qu[i].l;
        l1 = qu[i-1].l;
        while(l2>l1){
            coun[a[l1]]--;
            if(coun[a[l1]]==0)
                kq--;
            l1++;
        }
        while(l2<l1){
            coun[a[l2]]++;
            if(coun[a[l2]]==1)
                kq++;
            l2++;
        }
        r2 = qu[i].r;
        r1 = qu[i-1].r;
        while(r2>r1){
            coun[a[r2]]++;
            if(coun[a[r2]]==1)
                kq++;
            r2--;
        }
        while(r2<r1){
            coun[a[r1]]--;
            if(coun[a[r1]]==0)
                kq--;
            r1--;
        }
        kqq[qu[i].index]= kq;
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",kqq[i]);
}
int main()
{
    //freopen("code.in","r",stdin);
    input();
    init();
    solve();

}
