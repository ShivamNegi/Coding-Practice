#include <iostream>

using namespace std;

int count = 0;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     count ++;
   if (n == 0)
     return false;
 
   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}
 
// Driver program to test above function
int main()
{
  int t;
  cin>>t;

  while(t--)
  {
    int n;
    count = 0;
    cin>>n;

    int set[n];

    for(int i = 0; i < n; i++)
      {
       cin>>set[i];
       set[i]++; 
      }
    int sum = 1;
    if (isSubsetSum(set, n, sum) == true);
    cout<<count<<endl;
  }
  
  return 0;
}