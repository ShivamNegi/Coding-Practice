#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int max_div = 0;

        for(int no = 2;; no++)
            {
                int counter = 0; float sqrt_no = sqrt(no);
                for(int i = 2; i <= sqrt_no; i++)
                {
                    if(no % i == 0)
                        {
                            if(i != sqrt_no)
                                counter += 2;
                            else
                                counter++;
                        }

                }
                /*cout<<"for no: "<<no<<" the counter value is: "<<counter<<endl;*/
                if(counter > max_div)
                {
                    if(no > n)
                    {
                        cout<<no<<endl;
                        break;
                    }
                    max_div = counter;
                }
            }
    }
    return 0;
}