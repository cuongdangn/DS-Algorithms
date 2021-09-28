/*
    char from 'a' to 'z'
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_NCHAR = 28;
const int LOWEST_CHAR = 97; // = int('a')

struct Node {
    Node* next[MAX_NCHAR];
    int count_;
    int end_; //number of string in this node
    Node(){
        count_ = 0;
        end_ =0;
        for(int i=0;i<MAX_NCHAR;i++)
            next[i] = NULL;
    }
    Node(int t){
        count_ = t;
        end_ = 0;
        for(int i=0;i<MAX_NCHAR;i++)
            next[i] = NULL;
    }
    ~Node(){
        for(int i=0;i<MAX_NCHAR;i++)
            //if(next[i]!=NULL)
             delete next[i];
    }
};
struct Trie {
    Node* root;
    Trie(){
        root = new Node(0);
    }
    void add(const string s){
        Node* p = root;
        int n = s.length();
        for(int i=0; i<n; i++){
            int tmp = int(s[i])-LOWEST_CHAR;
            if(p->next[tmp]==NULL){
                p->next[tmp] = new Node();
            }
            p->next[tmp]->count_++;
            p=p->next[tmp];
        }
        p->end_++;
    }
    void add(char s[]){
        Node* p = root;
        int n = strlen(s);
        for(int i=0; i<n; i++){
            int tmp = int(s[i])-LOWEST_CHAR;
            if(p->next[tmp]==NULL){
                p->next[tmp] = new Node();
            }
            p->next[tmp]->count_++;
            p=p->next[tmp];
        }
        p->end_ ++;
    }

    bool deletenode_(Node* p,const string s,int i,const int n){

         if(i==n){

                if(p->end_ >0){
                        p->end_ --;
                        return true;
                }
                 else {
                        return false;
                 }

         }
            int tmp = int(s[i])-LOWEST_CHAR;
         if(p->next[tmp]==NULL) return false;
         bool ok = deletenode_(p->next[tmp],s,i+1,n);

         if(ok){
            if(p->count_ == 1) {
                    delete p->next[tmp];
                    p->next[tmp] = NULL;
            }
              else{
                    p->next[tmp]-> count_ --;
                  //  p->next[tmp]-> end_ --;
              }
         }
         return ok;
    }
    void delete_(const string s){
        int n = s.length();
        Node* p = root;
       // if(!deletenode_(root,s,0,n))
         //   cout << "s not belong trie" <<endl;
    }

    bool check(const string s){
        int n = s.length();
        Node* p = root;
        for(int i=0;i<n;i++){
            int tmp = int(s[i])-LOWEST_CHAR;
            if(p->next[tmp]==NULL) return false;
            p=p->next[tmp];
        }
        return p->end_ > 0;
    }
    void DFS(Node* p){
        if(p==NULL) return;
        cout << p->count_  << " "<<p->end_ <<endl;
        for(int i=0;i<MAX_NCHAR;i++)
            DFS(p->next[i]);
    }
};

Trie tree;

int main()
{
    //freopen("code.in","r",stdin);
    int n;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        cout << s <<endl;
        tree.add(s);
    }
    tree.DFS(tree.root);
    for(int i=1;i<=n;i++){
        cin >> s;
        cout << i << s<<endl;
        tree.delete_(s);
        tree.DFS(tree.root);
    }

}
