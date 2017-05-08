#include<bits/stdc++.h>

using namespace std;

int main()
{
 int t;
 cin>>t;

 vector <int> arr;

 for(int i = 0; i < t; i++)
    {
     int no;
     cin>>no;
     arr.push_back(no);
    }

 sort(arr.begin(), arr.begin() + t);

 /*
 for(int i = 0; i < t; i++)
    {
     for(int j = i + 1; j < t; j++)
        {
         if(arr[j] < arr[i])
            {
             int temp = arr[i];
             arr[i] = arr[j];
             arr[j] = temp;
            }
        }
    }
 */

 int max_val = 0;

 for(int i = 0; i < t; i++)
    {
     if(max_val < arr[i] * (t - i))
        {
         max_val = arr[i] * (t - i);
        }
    }

 cout<<max_val<<endl;

 return 0;
}
