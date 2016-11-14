#include <iostream>

using namespace std;

void display(char str[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<str[i];
    cout<<endl;
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int counter = 0;

void permutations(char str[], int pos, int n)
{
    if(pos == n - 1)
        {
            display(str, n);
            counter++;
        }
    else
    {
        for(int i = pos; i < n; i++)
        {
            swap(str[pos], str[i]);
            permutations(str, pos + 1, n);
            swap(str[pos], str[i]);
        }
    }
}

int main()
{
    int n;

    cout<<"Enter the string length: ";
    cin>>n;

    char str[n];

    for(int i = 0; i < n; i++)
        cin>>str[i];


    cout<<"\nThe permutations of the string are:\n";
    permutations(str, 0, n);

    cout<<"\nThe number of permutations are: "<<counter<<endl;
    return 0;
}