#include <iostream>

using namespace std;

int wt[100], value[100];
int counter = 0;

int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int wt[], int val[], int n)
{
   counter++;
   if (n == 0 || W == 0)
       return 0;
 
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}

int main()
{
    int n;
    
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter thr weight and the value: ";
        cin>>wt[i]>>value[i];
        marked[i] = 1;
    }
    
    int mwt;
    cout<<"Maximum weight: ";
    cin>>mwt;
    
    cout<<knapSack(mwt, wt, value, n)<<endl;
    cout<<counter<<endl;
    return 0;
}
