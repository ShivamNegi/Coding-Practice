#include <bits/stdc++.h>

using namespace std;

int main()
{
  int data[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10};
  vector<int> arr(data, data + sizeof(data) / sizeof(data[0]));

  int no;
  cin>>no;
  vector<int>::iterator it;
  it = lower_bound(arr.begin(), arr.end(), no);
  cout<<*it<<endl;
  
  return 0;
}
