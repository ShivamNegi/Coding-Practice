#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
using namespace std;

int maxSum(int v[], int pos, int prev, int n){   
  if(pos == n-1)
      return v[pos];
  if(v[pos]<0 && prev==0){
     int m = maxSum(v, pos+1, 0, n);
    int n = maxSum(v, pos+1, v[pos], n);
      return max(n, m+v[pos]);
  }
  else{
      int n = maxSum(v, pos+1, prev, n);
      return max(v[pos], n+v[pos]);
  }
}

int main(){
int t;
cin>>t;
while(t--){
    int n;
    int v[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"sdsd"<<endl;
    cout<<maxSum(v, 0, 0, n)<<'\n';
}


return 0;
}