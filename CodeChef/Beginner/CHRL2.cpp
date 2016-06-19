#include<iostream>
#include<string>

using namespace std;

int main()
{
    string inp, dup;
    int counter = 0;
    cin>>inp;

    int pos = inp.find_first_of('C'), inppos;
    inppos = pos;

    while(pos != -1)
    {
        dup = inp.substr(pos + 1, inp.length());
        inp.erase(inppos, 1);

        pos = dup.find_first_of('H');

        if(pos != -1)
        {
            // cout<<inp<<"\t"<<dup<<"\t"<<pos<<endl;
            dup = inp.substr(pos + 1, inp.length());
            inppos += pos;
            inp.erase(inppos, 1);

            pos = dup.find_first_of('E');

            if(pos != -1)
            {
                // cout<<inp<<"\t"<<dup<<"\t"<<pos<<endl;
                dup = inp.substr(pos + 1, inp.length());
                inppos += pos;
                inp.erase(inppos, 1);

                pos = dup.find_first_of('F');

                if(pos != -1)
                {
                    // cout<<inp<<"\t"<<dup<<"\t"<<pos<<endl;
                    inppos += pos;
                    inp.erase(inppos, 1);
                    counter++;                    
                }
                else
                    break;
            }
            else
                break;
        }
        else
            break;

        dup = inp;
        pos = dup.find_first_of('C');
        // cout<<inp<<"\t"<<dup<<"\t"<<pos<<endl;
        inppos = 0;
    }

    cout<<counter<<endl;
    return 0;
}