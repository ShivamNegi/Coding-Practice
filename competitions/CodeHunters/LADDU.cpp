#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
 int t;
 cin>>t;

 while(t--)
    {
     int n;
     cin>>n;

     int sum = 0;
     char national[20];
     cin>>national;


     for(int i = 0; i < n; i++)
        {
         char arr[50];
         cin>>arr;

         if(strcmp(arr, "COMPETITION_WON"))
            {
             int n;
             cin>>n;
             if(n < 20)
                sum += 300 + (20 - n);
             else
                sum += 300;
            }
         else if(strcmp(arr, "TOP_CONTRIBUTOR"))
            {
             sum += 300;
            }
         else if(strcmp(arr, "BUG_FOUND"))
            {
             int n;
             cin>>n;
             sum += n;
            }
         else if(strcmp(arr, "CONTEST_HOSTED"))
            {
             sum += 50;
            }
        }

    }
}
