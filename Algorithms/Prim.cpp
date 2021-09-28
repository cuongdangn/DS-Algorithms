#include <bits/stdc++.h>


#define ii pair<int, int>
#define li pair<long long, int>
#define il pair<int, long long>
#define oo_i INT_MAX
#define oo_l 100000000000000000
#define bug(i) cout << i <<endl;

using namespace std;

const int MAX_SIZE = 10008;
const int MAXM = 100005;
const int MAXN = 10008;

struct Node{  // add constructor
    int index; // index of vertical
    int key;
    bool priority(Node p){
        return (p.key>=key);
    }
    Node(int index_,int key_){
        key = key_;
        index = index_;
    }
    Node(){
        index = 0;
        key   = 0;
    }
};
struct Edge{
    int u,v,w;
    bool operator<(const Edge& rhs)const{
        return w<rhs.w;
    }
    Edge(int u1,int v1,int w1){
        u=u1;
        v=v1;
        w=w1;
    }
    Edge(){
        u=0;v=0;w=0;
    }
};
struct Heap{  // add pos

    int size_heap;
    Node heaplist[MAX_SIZE];
    int pos[MAXN];            // pos[i] :index of vertices i in HEAP

    Heap(){
        size_heap = 0;
        for(int i=1;i<=MAXN;i++)
            pos[i]=0;
    }

    void pop(){
        pos[heaplist[1].index] = 0;
        heaplist[1]= heaplist[size_heap];
        pos[heaplist[1].index]=1;
        size_heap--;
        downheap(1);
    }
    void add(int key){
        size_heap++;
        heaplist[size_heap].key = key;
        upheap(size_heap);
    }
    void add(Node node){
        size_heap++;
        heaplist[size_heap] = node;
        pos[node.index]=size_heap;
        upheap(size_heap);
    }
    void upheap(int c){
        do{
            int p = c/2;
            if(p==0 || heaplist[p].priority(heaplist[c])) break;
            Node tmp = heaplist[c];
            heaplist[c] = heaplist[p];
            heaplist[p] = tmp;
            pos[heaplist[p].index] =p;
            pos[heaplist[c].index] =c;
            c=p;
        }while(1);
    }
    void downheap(int p){
        do{
            int c = p*2;
            if(c<size_heap && heaplist[c+1].priority(heaplist[c]))c=c+1;
            if(c>size_heap || heaplist[p].priority(heaplist[c])) break;
            Node tmp = heaplist[c];
            heaplist[c] = heaplist[p];
            heaplist[p] = tmp;
            pos[heaplist[p].index] =p;
            pos[heaplist[c].index] =c;
            p = c;
        }while(1);
    }
    Node gettop(){
        return heaplist[1];
    }
};

Edge lis[MAXM];
int n,m;
int d[MAXN];
bool dd[MAXN];
vector<int> list_[MAXN];
Heap heap;
int sum;

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        sum+=w;
        lis[i] = Edge(u,v,w);
        list_[u].push_back(i);
        list_[v].push_back(i);
    }
}

void add(int v)
{
    int po = heap.pos[v];
   // if(v==8) cout << po <<" "<<d[8]<<endl;
    if(po){
        heap.heaplist[po].key = d[v];
        heap.upheap(po);
    }
    else {
        heap.add(Node(v,d[v]));
    }
  //  cout << "add: ";
    //for(int i=1;i<=heap.size_heap;i++)
      //  cout << heap.heaplist[i].index <<" ";
    //cout <<endl;
}
void init()
{
    for(int i=1;i<=n;i++){
        dd[i] = true;
        d[i] = oo_i;
    }
}
void Prim()
{
    init();
    int u = 1;
    int mst = 0;
    d[u]=0;
    for(int i=1;i<n;i++){
        dd[u] = false;
      //  cout << u << endl;
        for(int i=0;i<list_[u].size();i++){
            int k = list_[u][i];
            int v = lis[k].u+lis[k].v - u;
            if(dd[v]&&d[v]>lis[k].w){
                    d[v]=lis[k].w;
                    add(v);
            }
        }
        u = heap.gettop().index;
       // if(u==8)cout <<heap.pos[8]<<"x"<<endl;
        mst += heap.gettop().key;
        heap.pop();
     //   cout <<"pop: ";

   // for(int i=1;i<=heap.size_heap;i++)
       // cout << heap.heaplist[i].index <<" ";
    //cout <<endl;
    }
    //mst
    printf("%d",mst);
}
int main()
{
   //freopen("code.in","r",stdin);
    input();
    Prim();
}

