#include<bits/stdc++.h>
#include<algorithm>

using namespace std;



int main()
{
 int a, b;

 cin>>a>>b;

 int min_no;
 if(a > b)
    min_no = b;


 for(int i = 1; i <= min_no; i++)
    {
     int c = i;
     int area = 0;
     int s = (a + b + c) / 2;

     area = sqrt(s * (s - a) * (s - b) * (s - c)) / 2;
     int div[100];
     c = 0;

     for(int i = 0; i <= sqrt(area); i++)
        {
         if(area % i == 0)
            {
             c = i;
             c++;
            }
        }

     for(int i = 0; i < c; i++)
        {
         for(int j = 0; j < c; j++)
            {
             if(div[j] > div[i])
                {
                 int temp = div[i];
                 div[i] = div[j];
                 div[j] = temp;
                }
            }
        }

      int mid = c / 2;

      if(c % 2 == 1)
        for(int i = 0; i < mid; i++)
            {
             if(div[mid - i] * div[mid + i] == area)
                {
                 cout<<div[mid - i]<<endl<<div[mid + i]<<endl;
                }
            }
     else
        {
         for(int i = 0; i < mid; i++)
            {
             if(div[mid] * div[mid + 1] == area)
                cout<<div[mid - i]<<endl<<div[mid + i]<<endl;
            }
        }

    }

 return 0;
}

