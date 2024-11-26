#include<iostream>
using namespace std;
void countsort(int a[],int n,int pos){
    int ans[n];
    int freq[10]={0};
    for(int i=0;i<n;i++){
        freq[(a[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans[--freq[(a[i]/pos)%10]] = a[i];
    }
    for(int i=0;i<n;i++){
        a[i] = ans[i];
    }
}
void radixsort(int a[],int n){
    int mx = -1;
    for(int i=0;i<n;i++){
        if(mx<a[i]){
            mx = a[i];
        }
    }
    for(int pos=1;mx/pos>0;pos*=10){
        countsort(a,n,pos);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    radixsort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
