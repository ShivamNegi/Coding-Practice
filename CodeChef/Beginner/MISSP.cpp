#include <iostream>

using namespace std;

void display(int a[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int inp[n], counter[n];
        int lenno = 0;

        for(int i = 0; i < n; i++)
            counter[i] = 0;

        for(int i = 0; i < n; i++)
        {
            bool flag = false;
            int no, j;
            cin>>no;

            for(j = 0; j < lenno; j++)
            {
                if(no == inp[j])
                {
                    flag = true;
                    break;
                }
            }

            if(flag)
            {                counter[j]++;            }
            else
            {
                inp[lenno] = no;
                counter[lenno++]++;
            }
        }

        for(int i = 0; i < lenno; i++)
        {
            if(counter[i] % 2 != 0)
            {
                cout<<inp[i]<<endl;
                break;
            }
        }
    }
    return 0;
}