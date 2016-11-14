#include <iostream>

using namespace std;

int *a, ** mat, n, ind;

void fx(int arr[], int k, int i, int s)
{
    if(i >= n)
    {
        int l = 0;
        mat[ind] = (int *) malloc(sizeof(int) * k);

        for(; l < k; l++)
        {
            mat[ind][l] = arr[l];
        }

        ind++;
        return;
    }

    fx(arr, k, i + 1, s);
    arr[0] = a[i] + s;
    arr[1] = k + 1;
    arr[k] = a[i];

    fx(arr, k + 1, i + 1, s + a[i]);
    return ;
}

void disp()
{
    
}

int main()
{
    return 0;
}