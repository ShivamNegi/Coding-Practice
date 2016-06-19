#include <iostream>
#include <cmath>
#include <algorithm>
#define mod 1000000007

using namespace std;

void merge(long long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    long long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (abs(L[i]) >= abs(R[j]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(long long int arr[], int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      merge(arr, l, m, r);
   }
}

int cmp(int a, int b) {
    return abs(b) > abs(a);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, nos;
        cin>>n>>nos;

        long long int a[n];
        bool allneg = true;

        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i] >= 0)
                allneg = false;
        }

        // mergeSort(a, 0, n - 1);
        sort(a, a + n, cmp);

        long long int prod = 1;

        if(allneg)
        {
            for(int i = n -1 ; (n - 1) - i  < nos; i--)
                {
                    prod *= a[i];
                    prod = prod % mod;
                }
        }
        else
        {
            for(int i = 0; i < nos; i++)
            {
                prod *= a[i];
                prod = prod % mod;
            }

            if(prod < 0)
            {
                int j;
                long long int prod1 = prod;
                for(j = nos -1; j >= 0; j--)            
                {
                    if(a[j] < 0)
                        break;
                }

                prod /= a[j];

                for(j = nos; j < n; j++)
                {
                    if(a[j] >= 0)
                        break;
                }
               
                prod *= a[j];                

                for(j = nos -1; j >= 0; j--)            
                {
                    if(a[j] > 0)
                        break;
                }

                prod1 /= a[j];
                bool flag = false;
                for(j = nos; j < n; j++)
                {
                    if(a[j] < 0)
                        {
                            flag = true;
                            break;
                        }
                }

                if(flag)
                    {
                        prod1 *= a[j];   
                        if(prod < prod1)
                            prod = prod1;                
                    }                
            }            
        }
        
        prod = prod % mod;
        if(prod < 0)
            prod += mod;
        cout<<prod<<endl;
    }
    return 0;
}