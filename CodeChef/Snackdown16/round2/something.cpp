#include <bits/stdc++.h>

using namespace std;

int findMinRec(vector<int> arr, int i, int sumCalculated, int sumTotal)
{
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i==0)
        return abs((sumTotal-sumCalculated) - sumCalculated);
 
 
    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return min(findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal),
               findMinRec(arr, i-1, sumCalculated, sumTotal));
}
 
// Returns minimum possible difference between sums
// of two subsets
int findMin(vector<int> arr, int n)
{
    // Compute total sum of elements
    int sumTotal = 0;
    for (int i=0; i<n; i++)
        sumTotal += arr[i];
 
    // Compute result using recursive function
    return findMinRec(arr, n, 0, sumTotal);
}

void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> nos, odd, even;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            nos.push_back(no);
            char ch;
            cin>>ch;
        }
        int no;
        cin>>no;
        nos.push_back(no);

        for(int i = 0; i < nos.size(); i++)
        {
            if(i % 2 == 0)
                even.push_back(nos[i]);
            else
                odd.push_back(nos[i]);
        }

        // display(nos);
        // display(odd);
        // display(even);
        // cout<<findMin(even, even.size())<<endl;
        // cout<<findMin(odd, odd.size())<<endl;
        cout<<findMin(even, even.size()) + findMin(odd, odd.size())<<endl;
    }
    return 0;
}