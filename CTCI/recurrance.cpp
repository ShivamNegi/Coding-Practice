#include <iostream>

using namespace std;

void inserthash(int key[], int value[], int val, int &counter)
{
    for(int i = 0; i < counter; i++)
    {
        if(key[i] == val)
        {
            value[i]++;
            return;
        }
    }

    key[counter] = val;
    value[counter] = 1;
    counter++;
}

void display(int key[], int value[], int counter)
{
    for(int i = 0; i < counter; i++)
    {
        cout<<key[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < counter; i++)
    {
        cout<<value[i]<<" ";
    }
    cout<<endl;
}

void ans(int a[], int n)
{
    int key[n], value[n]; int counter = 0;

    for(int i = 0; i < n; i++)
    {
        inserthash(key, value, a[i], counter);
    }

    int no1, no2, no3;
    bool flag1, flag2, flag3;
    flag1 = flag2 = flag3 = false;

    for(int i = 0; i < counter; i++)
    {
        if(value[i] == 3 && !flag1)
        {
            no1 = key[i];
            flag1 = true;
        }
        else if(value[i] == 3 && !flag2)
        {
            no2 = key[i];
            flag2 = true;
        }
        else if(value[i] == 3 && !flag3)
        {
            no3 = key[i];
            flag3 = true;
        }
    }
    /*display(key, value, counter);*/
    cout<<no1<<"\t"<<no2<<"\t"<<no3;
}

int main()
{
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];

    ans(a, n);
    return 0;
}