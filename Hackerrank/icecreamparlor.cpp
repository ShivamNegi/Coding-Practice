#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>m>>n;

        vector<int> arr, copyarr;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
            copyarr.push_back(no);
        }

        // this sorts in ascending order
        sort(copyarr.begin(), copyarr.end());
        //display(copyarr);

        int i, j = copyarr.size() - 1;

        for(i = 0; i < j;)
        {
            int sum = copyarr[i] + copyarr[j];
            if(sum > m)
                j--;
            else if(sum < m)                
                i++;
            else break;
        }

        //cout<<copyarr[i]<<" "<<copyarr[j]<<endl;
        int pos1, pos2;
        bool flag1 = false, flag2 = false;

        for(int k = 0; k < arr.size(); k++)
        {
            if(arr[k] == copyarr[i] && !flag1)
                {
                    pos1 = k + 1;
                    flag1 = true;   
                    continue;
                }
            if(arr[k] == copyarr[j] && !flag2)                
                {
                    pos2 = k + 1;
                    flag2 = true;   
                }
            if(flag1 && flag2)
                break;
        }

        if(pos2 > pos1)
            cout<<pos1<<" "<<pos2<<endl;
        else
            cout<<pos2<<" "<<pos1<<endl;
    }
    return 0;
}