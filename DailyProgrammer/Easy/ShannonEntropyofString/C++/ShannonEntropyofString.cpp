#include<bits/stdc++.h>

using namespace std;

int main()
{
 string inp;
 int len;

 cin>>inp;
 len = inp.size();

 float h = 0;

 string ele;

 for(int i = 0; i < len; i++)
    {
     char ch = inp[i];
     bool flag = true;
     for(int j = 0; j < ele.size(); j++)
        {
         if(ch == ele[j])
            {
             flag = false;
             break;
            }
        }
     if(flag)
        ele += ch;
    }

 for(int i = 0; i < ele.size(); i++)
    {
     char ch = ele[i];
     int counter = 0;
     for(int j = 0; j < len ;j++)
        {
         if(ch == inp[j])
            counter ++;
        }
     float k;
     k = float(counter) / len;
     h += k * log(k) / log(2);
    }

 h *= -1;
 cout<<h<<endl;
 return 0;
}

