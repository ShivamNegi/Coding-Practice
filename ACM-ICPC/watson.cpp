#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n, m, d, D;
		cin>>n>>m>>d>>D;
		if(n*d>m || n*D<m)
			cout<<-1;
		else{
			int k=m/n;
			int l=m%n;
			for(int i=0;i<n;i++){
				for(int j=0;j<k;j++){
					cout<<i+1<<" "<<(i+j)%n+1<<endl;
				}
			}
			for(int i=0;i<l;i++)
				cout<<i+1<<" "<<(i+k)%n+1<<endl;
		}
		cout<<endl;
	}
}