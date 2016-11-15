#include <iostream>

using namespace std; 

int wt[100], value[100];

int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
                 K[i][w] = 0;
           else if (wt[i-1] > w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
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
    }
    
    int mwt;
    cout<<"Maximum weight: ";
    cin>>mwt;
    
    cout<<knapSack(mwt, wt, value, n)<<endl;
    return 0;
}
