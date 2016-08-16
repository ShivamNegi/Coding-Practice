#include <iostream>

using namespace std;

int get_binary(int no)
{
    if(no < 2)
        return no;
    else
        return get_binary(no / 2) * 10 + no % 2;
}

int get_bin_len(int no)
{
    int len = 0;

    while(no != 0)
    {
        no /= 2;
        len++;
    }

    return len;
}

int main()
{
    int no;
    cin>>no;

    cout<<get_binary(no)<<endl;
    int len = get_bin_len(no) - 1;
    bool flag = true;

    for(int i = no - len; i < no; i++)
    {
        if(i + get_bin_len(i) == no)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout<<"not bleak\n";
    else
        cout<<"bleak\n";
    return 0;
}