#include <iostream>

using namespace std;

void display(int ** a, int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
  }

}

int main()
{
  int n;
  cin>>n;

  int ** array;
  array = new int *[n];
  for(int i = 0; i < n; i++)
  {    
    array[i] = new int[n];
    for(int j = 0; j < n; j++)
      array[i][j] = i + j;
  }
  display(array, n);
  return 0;
}