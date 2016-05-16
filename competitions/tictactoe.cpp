#include<bits/stdc++.h>

using namespace std;

int main()
{
 char inp[20], inp1[20];
 int t;

 cin>>t;

 while(t--)
    {
        cin>>inp;
        int l = strlen(inp);

        for(int i = 0; i < l ; i++)
            {
             for(int j = i + 1; j < l; j ++)
                {
                 if(inp[i] > inp[j])
                    {
                     char temp = inp[i];
                     inp[i] = inp[j];
                     inp[j] = temp;
                    }
                }
            }
        puts(inp);
    }

 return 0;
}
