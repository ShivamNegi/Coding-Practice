#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int * sol, counter = 0;

void clear()
{
    for(int i = 0; i < counter; i++)
        sol[i] = 0;
    counter = 0;
}

void knapsack(int wt[], int val[], int n, int cap)
{
    int lim = 1<<n;
    int maxval = 0;

    for(int i = 0; i < lim; i++)
    {
        int tempwt, tempval;
        tempval = tempwt = 0;

        for(int j = 1; j < lim;)
        {
            if( (j & i) > 0)
            {
                int position = log(j) / log(2);
                tempwt += wt[position];
                tempval += val[position];
            }

            j = j<<1;
        }

        if(tempwt < cap)
        {
            if(tempval > maxval)
            {
                clear();
                sol[counter++] = i;
                maxval = tempval;
            }
            else
                sol[counter++] = i;
        }
    }
}

void display()
{
    for(int i = 0; i < counter; i++)
        cout<<sol[i]<<"\t";
    cout<<endl;
}

int main()
{
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int wt[n], val[n];

    cout<<"Please enter the weights: ";
    for(int i = 0; i < n; i++)
        cin>>wt[i];

    cout<<"Please enter the values: ";
    for(int i = 0; i < n; i++)
        cin>>val[i];

    int cap;

    cout<<"Please enter the knapsack capacity: ";
    cin>>cap;

    sol = (int *) malloc(sizeof(int) * n);

    cout<<"\nKnapsack contains the following items:\n";
    knapsack(wt, val, n, cap);
    display();
    return 0;
}