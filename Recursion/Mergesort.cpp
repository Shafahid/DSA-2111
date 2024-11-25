#include<bits/stdc++.h>
using namespace std;
void merged(int a[],int l,int r,int mid){
int l_sz = mid-l+1;
int L[l_sz];
int r_sz = r-mid;
int R[r_sz];
for(int i=0;i<l_sz;i++){
    L[i] = a[i+l];
}
for(int i=0;i<r_sz;i++){
    R[i] = a[i+mid+1];
}
int l_i=0;
int r_i=0;
int k=l;
while(l_i<l_sz&&r_i<r_sz){
    if(L[l_i]<R[r_i]){
        a[k++] = L[l_i++];
    }else{
        a[k++] = R[r_i++];
    }
}
while(l_i<l_sz) a[k++] = L[l_i++];
while(r_i<r_sz) a[k++] = R[r_i++];

}
void mergesort(int a[],int l,int r){
if(l==r) return;
int mid = (l+r)/2;
mergesort(a,l,mid);
mergesort(a,mid+1,r);
merged(a,l,r,mid);

}
int main(){
int n;
cin >> n;
int a[n];
for(int i=0;i<n;i++){
cin >> a[i];

}
mergesort(a,0,n-1);
for(int i=0;i<n;i++){
cout << a[i] << " ";
}
return 0;
}
