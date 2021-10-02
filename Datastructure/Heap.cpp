/*
    size_heap : HEAP's size;
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 100000;

struct Node{
    int key;
    bool priority(Node p){
        return (p.key<=key);
    }
    Node(int key_){
        key = key_;
    }
    Node(){
        key = 0;
    }
};

struct Heap{

    int size_heap;
    Node heaplist[MAX_SIZE];


    Heap(){
        size_heap = 0;
    }

    void pop(){
        heaplist[1]= heaplist[size_heap];
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
        upheap(size_heap);
    }
    void upheap(int c){
        do{
            int p = c/2;
            if(p==0 || heaplist[p].priority(heaplist[c])) break;
            Node tmp = heaplist[c];
            heaplist[c] = heaplist[p];
            heaplist[p] = tmp;
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
            p = c;
        }while(1);
    }
    Node gettop(){
        return heaplist[1];
    }
};

int main()
{

}
