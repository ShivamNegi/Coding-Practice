#include <iostream>
#include <locale>

using namespace std;

int main()
{
    string inp;
    bool arr[26];

    getline(cin, inp);

    for(int i = 0; i < inp.length(); i++)
        {
            if(isalpha(inp[i]))
                inp[i] = tolower(inp[i]);
        }

    // cout<<inp<<endl;
    for(int i = 0; i < 26; i ++)
        arr[i] = false;

    for(int i = 0; i < inp.length(); i++)
    {
        if(!isalpha(inp[i]))
            continue;
        else if(!arr[inp[i] - 'a'])
            arr[inp[i] - 'a'] = true;
    }

    bool flag = true;

    for(int i = 0; i < 26; i++)
        {
            if(arr[i] == false)
            {
                flag = false;
                break;
            }
        }

    if(flag)
    {
        cout<<"pangram\n";
    }
    else
        cout<<"not pangram\n";


    return 0;
}