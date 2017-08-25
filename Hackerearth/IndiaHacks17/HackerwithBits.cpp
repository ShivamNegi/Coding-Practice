#include <bits/stdc++.h>

using namespace std;

int count_ones(bitset<len> arr)
{
    int val = 0, max_val = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 1)
            val++;
        else
        {
            if(val > max_val)
                max_val = val;
            val = 0;
        }
    }
    return max_val;
}

int longest_seq(bitset<len> arr, vector<int> zero_pos, vector<int> one_pos)
{
  int max_len = 0;
  for(int i = 0; i < zero_pos.size(); i++)
    {
      arr[zero_pos[i]] = 1;
      for(int j = 0; j < one_pos.size(); j++)
	{
	  arr[one_pos[j]] = 0;
	  int val = count_ones(arr);
	  if(val > max_len)
	    max_len = val;
	  arr[one_pos[j]] = 1;
	}
      arr[zero_pos[i]] = 0;
    }
  return max_len;
}

int main()
{
    int len;
    cin>>len;

    bitset<100> arrp;
    vector<int> zero_pos, one_pos;
    for(int i = 0; i < len; i++)
    {
        int no;
        cin>>no;
        arr[i] = no;
        if(no == 0)
            zero_pos.push_back(i);
        else
            one_pos.push_back(i);
    }

    cout<<longest_seq(arr, zero_pos, one_pos, len)<<endl;

    return 0;
}
