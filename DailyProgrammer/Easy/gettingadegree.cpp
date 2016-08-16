#include <iostream>
#include <cmath>

using namespace std;

float convert(float val, char inp, char out)
{
    float res;
    switch(inp)
    {
        case 'c':
                    if(out == 'k')
                        res = val + 273.5;
                    else
                        res = (val / 5) * 9 + 32;
                    break;
        case 'f':
                    res = (val - 32) / 9 * 5;
                    if(out == 'k')
                        res = res + 273.5;
                    break;
        case 'k':
                    res = val - 273.5;
                    if(out == 'f')
                        res = (res / 5) * 9 + 32;
                    break;
    }
    return res;
}

int main()
{
    string inp;
    cin>>inp;

    float count = 0;
    int decipower = 0;

    for(int i = 0; i < inp.length() - 2; i++)
    {
        if(inp[i] != '.' && decipower == 0)
            count = count * 10 + (inp[i] - '0');
        else if(inp[i] == '.')
            decipower = 1;
        else
            count = count + (inp[i] - '0') / pow(10, decipower++);        
    }

    cout<<convert(count, inp[inp.size() - 2], inp[inp.size() - 1])<<inp[inp.size() - 1]<<endl;

    return 0;
}