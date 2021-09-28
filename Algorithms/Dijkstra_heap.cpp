/*
    Graph use vertices list
    Undirected graph
*/

#include <bits/stdc++.h>

#define ii pair<int ,int>
#define bug(i) cout << i;

const int MAXN = 100000;
const int MAX_SIZE = MAXN;
const int oo_i = INT_MAX;

using namespace std;

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

struct Heap{  // add pos

    int size_heap;
    Node heaplist[MAX_SIZE];
    int pos[MAXN];            // pos[i] :index of vertices i in HEAP

    Heap(){
        size_heap = 0;
    }

    void pop(){
        pos[heaplist[1].index] = 0;
        heaplist[1]= heaplist[size_heap];
        pos[heaplist[1].index] = 1;
        size_heap--;
        downheap(1);
    }

    void add(Node node){
        size_heap++;
        heaplist[size_heap] = node;
        pos[node.index] = size_heap;
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


vector <ii> listv[MAXN];
int d[MAXN],n,m,s;
Heap heap;

void    input()
{
    int u,v,w;
    scanf("%d%d",&n,&m); // n : the number of vertices ; m : is the number of edges
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        listv[u].push_back(ii(v,w));
        listv[v].push_back(ii(u,w));
    }
    scanf("%d",&s);    // s : started vertice;
}
void    addheap(int v,int w){
    int po = heap.pos[v];
    if(po){
        heap.heaplist[po].key = w;
        heap.upheap(po);
    }
    else {
        heap.add(Node(v,w));
    }
}
void    init()
{
    for(int i=1;i<=n;i++)
        d[i] = oo_i;
    d[s]=0;
    addheap(s,0);
}
void dijkstra()
{
    init();
    while(heap.size_heap){
        Node p = heap.gettop();
        heap.pop();
        int u = p.index;
       // int w = p.key;

        for(int i=0;i<listv[u].size();i++)
        {
            int v = listv[u][i].first;
            int w1 = listv[u][i].second;
            if(d[v]>d[u]+w1){
                d[v] = d[u]+w1;
                addheap(v,d[u]+w1);
            }

        }
    }


    for(int i=1;i<=n;i++)
        cout << d[i] <<" ";

}
int main()
{
    freopen("code.in","r",stdin);
    input();
    dijkstra();
}
