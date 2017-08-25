#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a>b?a:b;
}

int lcs(string inp1, string inp2)
{
    int n1 = inp1.length(), n2 = inp2.length();
    int val[n1][n2];

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(i == 0 || j == 0)
                val[i][j] = 0;
            else
            {
                int temp = max(val[i - 1][j], val[i][j - 1]);
                if(inp1[i] == inp2[j])
                    val[i][j] = val[i - 1][j - 1] + 1;
                else
                    val[i][j] = temp;
            }
        }
    }
    return val[n1 - 1][n2 - 1];
}

int main()
{
    string inp1, inp2;

    cin>>inp1>>inp2;

    cout<<"Length of longest common subsequence is: "<<lcs(inp1, inp2)<<endl;

    return 0;
}