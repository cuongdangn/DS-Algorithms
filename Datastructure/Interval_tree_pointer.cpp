/*
    Interval tree lazy_update
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;


struct Node{
    int key;
    int add;
    Node* left;
    Node* right;
    Node(){
        key = 0;
        add = 0;
    }
    Node(int k){
        key = k;
        add = 0;
    }
    bool operator>(const Node* otherN)const {
        return key > otherN->key;
    }

    bool operator<(const Node* otherN)const {
        return key < otherN->key;
    }
    Node operator+(const Node* otherN)const {
        return Node(key+otherN->key);
    }

};
struct ITree{
    Node* root;
    ITree(){
        root = NULL;
    }
    Node* build(int*,int,int,Node* ff(Node*,Node*));
    Node* build(int,int,Node* ff(Node*,Node*));
    void updatefor_(Node*);
    void update(Node*,int,int,int,int,Node* ff(Node*,Node*),int);
    Node* get(Node*,int,int,int,int,Node* ff(Node*,Node*));

};
Node* ITree::build(int *a,int l,int r,Node* ff(Node*,Node*)){  //ff truyen ham vao nhu max or min
        //cout << a << endl;
     //   if(l>r) return NULL;
        Node* newNode = new Node();
        if(l==r){
            newNode->key=*(a+l-1);
            newNode->add = 0;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        int mid = (l+r)/2;
        newNode->left = build(a,l,mid,ff);
        newNode->right=build(a,mid+1,r,ff);
        newNode->key=ff(newNode->left,newNode->right)->key;
        newNode->add = 0;
        return newNode;
}
Node* ITree::build(int l,int r,Node* ff(Node*,Node*)){  //ff truyen ham vao nhu max or min
        //cout << a << endl;
       // if(l>r) return NULL;
        Node* newNode = new Node();
        if(l==r){
            newNode->key=0;
            newNode->add = 0;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        int mid = (l+r)/2;
        newNode->left = build(l,mid,ff);
        newNode->right=build(mid+1,r,ff);
        newNode->key=ff(newNode->left,newNode->right)->key;
        newNode->add = 0;
        return newNode;
}
void ITree::updatefor_(Node *k){
    if(k->left!=NULL){
        k->left->key += k->add;
        k->left->add += k->add;
    }
    if(k->right !=NULL){
        k->right->key += k->add;
        k->right->add += k->add;
    }
    k->add = 0;
}
void ITree::update(Node* k,int l,int r,int i,int j,Node* ff(Node*,Node*),int t){ //ff truyen ham vao, tang tu i den j t don vi
        if(l>=i && r<=j) {
            k->key+=t;
            k->add+=t;
            return;
        }
        int mid = (l+r) / 2;
        updatefor_(k);
        if(j<=mid) update(k->left,l,mid,i,j,ff,t);
         else if(i>=mid+1) update(k->right,mid+1,r,i,j,ff,t);
          else{
            update(k->left,l,mid,i,j,ff,t);
            update(k->right,mid+1,r,i,j,ff,t);
          }
        k->key=ff(k->left,k->right)->key;
}
Node* ITree::get(Node* k,int l,int r,int i,int j,Node* ff(Node*,Node*)){ //ff truyen ham vao
      //  cout << k->key <<" "<<l<<" "<<r<<endl;
        if(l>=i && r<=j) return k;
        int mid = (l+r) / 2;
        updatefor_(k);
        if(j<=mid) return get(k->left,l,mid,i,j,ff);
        if(i>=mid+1) return get(k->right,mid+1,r,i,j,ff);
        Node* left = get(k->left,l,mid,i,j,ff);
        Node* right = get(k->right,mid+1,r,i,j,ff);
        return ff(left,right);
}

Node* ffmin(Node* a,Node* b){
    return (a->key>b->key)?b:a;
}
Node* ffmax(Node* a,Node* b){
    return (a->key<b->key)?b:a;
}

int n,m;
ITree tree;
int main()
{
 /*   srand(time(NULL));
    for(int i=1;i<=6;i++)
        a[i] = rand()%100;
    for(int i=1;i<=6;i++)
        cout << a[i]<< " ";
    cout << endl;
    cout << &(a[1]) << endl;
    tree.build(&a[1],1,1,6,ffmin);
    cout << tree.get(1,1,6,2,5,ffmin).key;
    */
  // freopen("code.in","r",stdin);
  /*
    int l,u,v,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&x);
        a[u]+=x;
        a[v+1]-=x;
    }
    for(int i=1;i<=n;i++)
        a[i]=a[i]+a[i-1];
  //  for(int i=1;i<=n;i++)
   //     cout << a[i] << endl;

    tree.root= tree.build(&a[1],1,n,ffmax);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            printf("%d\n",tree.get(tree.root,1,n,u,v,ffmax)->key);
        }
    */
     int l,u,v,x;
    scanf("%d%d",&n,&m);
    tree.root=tree.build(1,n,ffmax);
    for(int i=1;i<=m;i++){
        int l;
        scanf("%d",&l);
        if(l==0){
            scanf("%d%d%d",&u,&v,&x);
            tree.update(tree.root,1,n,u,v,ffmax,x);
        }
        else{
            scanf("%d%d",&u,&v);
            printf("%d\n",tree.get(tree.root,1,n,u,v,ffmax)->key);
        }
    }

}


