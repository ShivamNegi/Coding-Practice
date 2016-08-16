#include <bits/stdc++.h>

using namespace std;

char* wordrevstr(char * a)
{
    int l = strlen(a);
    int prev, curr;
    prev = curr = 0;

    for(int i = 0; i < l; i++)
    {
        if(a[i] == ' ')
        {
            curr = i - 1;
            int j = prev, k = curr, mid;
            mid = (j + k) / 2;

            for(j; j <= mid; j++)
            {
                char temp = a[j];
                a[j] = a[k];
                a[k] = temp;
                k--;
            }
            prev = i + 1;
        }
    }

    return a;
}

int main()
{
    char a[100];
    cin>>a;
    cout<<wordrevstr(a);
    return 0;
}