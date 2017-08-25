#include <iostream>

using namespace std;

void display(int arr[], char alpha[], int size, int start, int end)
{
    string out ="";
    int val;
    bool flag = true;

    for(int k = 0; k < size; k++)
    {
        if(k == start || k == end)
        {
            val = arr[k] * 10;
            continue;
        }
        if(k == start + 1 || k == end + 1)
        {
            val += arr[k];
        }
        else
            val = arr[k];
        if(val > 26)
        {
            flag = false;
            break;
        }
        out += alpha[val - 1];
    }
    if(flag)
        cout<<out<<endl;
}

void inp(int arr[], char alpha[], int size)
{
    string out = "";
    for(int i = 0; i < size; i++)
        out = out + alpha[arr[i] - 1];
    cout<<out<<endl;

    for(int i = 0; i < size - 1; i++)
    {
        display(arr, alpha, size, i, i);

        for(int j = i + 2; j < size - 1; j++)
        {
            display(arr, alpha, size, i, j);            
        }
    }
}

int main()
{
    int no;
    cin>>no;

    int rev_arr[100], arr[100], size;
    size = 0;
    while(no > 0)
    {
        rev_arr[size++] = no % 10;
        no /= 10;
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = rev_arr[size - i - 1];
    }

    char alpha[26];
    for(int i = 0; i < 26; i++)
    {
        alpha[i] = char(97 + i);
    }

    inp(arr, alpha, size);
    return 0;
}