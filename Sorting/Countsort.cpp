#include<iostream>
using namespace std;
void countsort(int a[],int n){
    int ans[n];

    int mx = -1;
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx = a[i];
        }
    }

    int freq[mx+1]={0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }

    for(int i=1;i<=mx;i++){
        freq[i]+=freq[i-1];
    }

    for(int i=n-1;i>=0;i--){
        ans[--freq[a[i]]] = a[i];
    }

    for(int i=0;i<n;i++) a[i] = ans[i];
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    countsort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
