#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string inp, rinp = "";
    cin>>inp;

    // making a reverse of the given string    
    for(int i = 0; i < inp.length(); i++)
        rinp = inp[i] + rinp;

    int w, l, len = inp.length();
    cin>>w>>l;

    bool rev = false;

    // the first row will be reversed or not
    if( ((w + 1) / 2) % 2 != 0 )
        rev = true;

    int somelen = l * len - 1, somewidth = w * len - w + 1;

    // clearing the matrix
    char a[somewidth][somelen];
    for(int i = 0; i < somewidth; i++)
    {
        for(int j = 0; j < somelen; j++)
            a[i][j] = ' ';
    }

    //shaping
    for(int i = 0; i < somewidth; i++)
    {
        int val = i % (len - 1);
        if(val == 0)
            if(!rev)
            {
                for(int j = 0; j < len; j++)
                {
                    a[i][j] = inp[j];
                }

                for(int j = 1; j < l; j++)
                {
                    int counter = 1;
                    if(rinp[len - 1] == a[i][j * (len - 1)])
                        for(int k = j * (len - 1) + 1; k < (j + 1) * (len - 1) + 1; k++)
                            a[i][k] = inp[counter++];
                    else
                        for(int k = j * (len - 1) + 1; k < (j + 1) * (len - 1) + 1; k++)
                            a[i][k] = rinp[counter++];
                }
                // nice one to switch between true and false
                rev = rev ^ true;
            }
            else
            {
                for(int j = 0; j < len; j++)
                {
                    a[i][j] = rinp[j];
                }

                for(int j = 1; j < l; j++)
                {
                    int counter = 1;
                    if(rinp[len - 1] == a[i][j * (len - 1)])
                        for(int k = j * (len - 1) + 1; k < (j + 1) * (len - 1) + 1; k++)
                            a[i][k] = inp[counter++];
                    else
                        for(int k = j * (len - 1) + 1; k < (j + 1) * (len - 1) + 1; k++)
                            a[i][k] = rinp[counter++];
                }
                rev = rev ^ true;
            }
        else
        {
            int pos = 0;
            bool flag = a[i - val][0] == inp[0];
            for(int k = 0; k <= l; k++)
            {
                if(flag)
                    a[i][k * (len - 1)] = inp[val];
                else
                    a[i][k * (len - 1)] = rinp[val];
                flag = flag ^ true;
            }
        }
    }

    for(int i = 0; i < somewidth; i++)
    {
        for(int j = 0; j < somelen; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}