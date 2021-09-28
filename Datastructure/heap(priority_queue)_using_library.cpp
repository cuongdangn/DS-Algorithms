#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,greater<int> > heap_min; // heap min
priority_queue<int> heap_max;

int main()
{
    heap_max.push(1);heap_max.push(6);heap_max.push(3);
    cout << heap_max.top() <<endl;
    heap_min.push(1);heap_min.push(6);heap_min.push(3);
    cout << heap_min.top();
}
