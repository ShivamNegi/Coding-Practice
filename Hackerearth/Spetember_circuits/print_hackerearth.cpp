#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
 int n;
 cin>>n;
 string inp;
 cin>>inp;
 string word = "hackerearth", set_word = "hackert";

 int min_no = count(inp.begin(), inp.end(), 'h');
 
 for(int i = 0; i < set_word.length(); i++)
 {
    int val = floor(count(inp.begin(), inp.end(), set_word[i]) / count(word.begin(), word.end(), set_word[i]));
    if(val < min_no)
        min_no = val;
 }

 cout<<min_no<<endl;
 return 0;
}
