/*
    Interval tree (no lazy update )
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;


struct Node{
    int key;
    Node(){
        key = 0;
    }
    Node(int k){
        key = k;
    }
    bool operator>(const Node otherN)const {
        return key > otherN.key;
    }

    bool operator<(const Node otherN)const {
        return key < otherN.key;
    }
    Node operator+(const Node otherN)const {
        return Node(key+otherN.key);
    }

};
struct ITree{
    int size_;
    Node it[4*MAXN+5];

    ITree(){
        size_ = 0;
    }
    ITree(int sz){
        size_ = sz;
    }

    void build(const int a[],int i,int l,int r,Node ff(Node,Node)){  //ff truyen ham vao nhu max or min
        if(l>r) return;
        if(l==r){
            it[i].key=a[l];
            return;
        }
        int mid = (l+r)/2;
        build(a,i*2,l,mid,ff);
        build(a,i*2+1,mid+1,r,ff);
        it[i]=ff(it[i*2],it[i*2+1]);
    }

    Node get(int k,int l,int r,int i,int j,Node ff(Node,Node)){ //ff truyen ham vao
        if(l>=i && r<=j) return it[k];
        int mid = (l+r) / 2;
        if(j<=mid) return get(k*2,l,mid,i,j,ff);
        if(i>=mid+1) return get(k*2+1,mid+1,r,i,j,ff);
        Node left = get(k*2,l,mid,i,j,ff);
        Node right = get(k*2+1,mid+1,r,i,j,ff);
        return ff(left,right);
    }

};
Node ffmin(Node a,Node b)
{
    return (a>b)?b:a;
}
Node ffmax(Node a,Node b)
{
    return (a<b)?b:a;
}
int main()
{
    cout << 1;
}
