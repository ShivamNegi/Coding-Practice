#include<iostream>
#include<string>

using namespace std;

int main()
{
    string inp;
    cin>>inp;

   int found = inp.find_last_of("C");
   int counter = 0;

   while(found != -1)
   {
    //cout<<inp<<endl;
    inp.erase(found, 1);
    if((found = inp.find_first_of("H", found, inp.length())) != -1)
    {
        inp.erase(found, 1);
        if((found = inp.find_first_of("E", found, inp.length())) != -1)
        {
            inp.erase(found, 1);
            if((found = inp.find_first_of("F", found, inp.length())) != -1)
            {
                inp.erase(found, 1);
                counter++;
            }   
        }
    }
    found = inp.find_last_of("C");
   }

    cout<<counter<<endl;
    return 0;
}