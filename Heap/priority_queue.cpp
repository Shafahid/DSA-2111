#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> p; //max heap
    priority_queue<int,vector<int>,greater<int>> pq; //min heap
    p.push(1);
    p.push(2);
    p.push(3);
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    pq.push(3);
    pq.push(2);
    pq.push(1);
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}
