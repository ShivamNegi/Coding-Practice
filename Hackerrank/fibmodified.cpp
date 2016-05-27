#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void display(int arr[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

void copy(int from[], int size, int * to)
{
    for(int i = 0; i <= size; i++)
    {
        to[i] = from[i];
    }
}

void multiplyarr(int * arr1, int len1, int arr2[], int len2)
{
 vector<int> temparr;

 for(int i = 0; i <= len1; i++)
 {
    for(int j = 0; j <= len2; j++)
    {
        int temp = arr1[i] * arr2[j], carry; // 3 * 5

        if(temp > 10)
        {
            carry = temp / 10; // 1            
            temp = temp % 10; // 5
        }
        if(j + i > temparr.size()) // temparr.size is 0 initially
        {
            temparr.push_back(temp); // 1 inserted
            temparr.push_back(carry); // 5 inserted
        }
        else if(j + i + 1 > temparr.size() && carry > 0)
        {
            int addcarry = 0;
            temparr[i + j] += temp;
            if(temparr[i + j] > 10)
            {
                addcarry = temparr[i + j] / 10;
                temparr[i + j] = temparr[i + j] % 10;
            }
            carry += addcarry;

            if(carry > 10)
            {
                addcarry = carry / 10;
                carry = carry % 10;
            }
            temparr.push_back(carry);
            temparr.push_back(addcarry);
        }

    }
 }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int a, b, n, temp;
    int prevarr[200], newarr[200], newlen, prevlen;
    newlen = prevlen = 0;
    int counter = 1;
    
    cin>>a>>b>>n;
    prevarr[0] = a;
    newarr[0] = n;
    
    multiplyarr(newarr, newlen, newarr, newlen);
    display(newarr, newlen);
    //display(prevarr, prevlen);
    //display(newarr, newlen);
    
    /*
    while(counter != n)
        {
        int temparr[200], templen = newlen;
               
        copy(newarr, newlen, temparr);
        multiplyarr(newarr, newlen, newarr, newlen);
        addarr(newarr, newlen, prevarr, prevlen);        
        copy(temparr, templen, prev);
        }
    */        
    
    cout<<endl;
    return 0;
}
