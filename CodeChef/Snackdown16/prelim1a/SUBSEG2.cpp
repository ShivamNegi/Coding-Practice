#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*void display(vector<pair<long int, long int> > a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }

}*/
 
int main(){
    
    long int n, q;
    cin>>n>>q;
    vector<pair<long int, long int> > a(n);//, b(q);
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    /*for(int i=0;i<q;i++)
        cin>>b[i].first>>b[i].second;*/
    
    sort(a.begin(), a.end(), [](const pair<long int, long int>&left, const pair<long int, long int>&right){
        return left.second < right.second;
    });

 
    for(int j=0;j<q;j++){
        long int first, second;
        cin>>first>>second;
        vector<pair<long int, long int> > ss(n);

        int k=0;
        for(int i=0;i<n;i++){
            if(a[i].second<=second && a[i].first>=first){
                ss[k]=a[i];
                k++;
            }
            else if(a[i].second>second)
                break;
        }
        
        int tasks=0;
        
        if(k){
            int last=0;
            tasks=1;
 
            for(int i=1;i<k;i++){
                if(ss[i].first>=ss[last].second){
                    tasks++;
                    last=i;
                }
            }
        }
        cout<<tasks<<endl;
    }
    return 0;   
}