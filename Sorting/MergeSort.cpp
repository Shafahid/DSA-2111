#include<bits/stdc++.h>
using namespace std;
void merged(int a[],int l,int r,int mid){
  int i = l;
  int j = mid + 1;
  int k = 0;
  int c[r-l+1];
  while(i<=mid&&j<=r){
    if(a[i]<=a[j]){
      c[k++] = a[i++];
    }else{
      c[k++] = a[j++];
    }
  }
  while(i<=mid) c[k++] = a[i++];
  while(j<=r) c[k++] = a[j++];
  for(int i=l;i<=r;i++){
    a[i] = c[i-l];
  }
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
