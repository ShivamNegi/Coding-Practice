#include <bits/stdc++.h>

using namespace std;

bool binary_search(vector<long long> sorted_vec, long long key) {
   int mid, left = 0 ;
   int right = sorted_vec.size() - 1;

   while (left <= right) {
      mid = (left + right) /2;
      if (key > sorted_vec[mid]){
            left = mid + 1;
      }
      else if (key < sorted_vec[mid]){                                        
            right = mid - 1;
      }
      else {                                                                  
        return true;
     }                                                                                                               
   }

   return false;      
}

int main()
{
  vector<long long> a;
  int n;
  cin>>n;


  for(int i = 0; i < n; i++)
  {
    int no;
    cin>>no;
    a.push_back(no);
  }

  sort(a.begin(), a.end());
  if(binary_search(a, 4))
    {cout<<"Present";}
  return 0;
}