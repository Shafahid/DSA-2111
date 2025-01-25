#include<iostream>
using namespace std;

// 1) Convert the array into a max heap
// 2) Replace first element with last element
// 3) decrease size by one
// 4) apply heapify

void Heapify(int a[],int index,int n){
    int largest = index;
    int l = 2*index+1;
    int r = 2*index+2; 
    if( l < n && a[largest] < a[l]){
        largest = l;
    }
    if( r < n && a[largest] < a[r]){
        largest = r;
    }
    if(index!=largest){
    swap(a[largest],a[index]);
    Heapify(a,largest,n);
    }
}

void build_max_heap(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(a,i,n);
    }
}
// Time Complexity: O(NLOGN)
// Space Complexity: O(1)
int main(){
    int arr[] = {10,9,8,6,7,5,4,1,2,3};
    build_max_heap(arr,10);
    int sz = 10;
    while(sz>0){
        swap(arr[0],arr[sz-1]);
        sz--;
        Heapify(arr,0,sz);
    }
    for(int i=0;i<10;i++) cout<<arr[i]<<" ";
    return 0;
}
