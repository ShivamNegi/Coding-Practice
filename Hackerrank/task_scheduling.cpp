#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int d[n], m[n];

    for(int i = 0; i < n; i++)
    {
        cin>>d[i];
        cin>>m[i];
    }

    int counter = 0, timeline = 0;

    while(counter != n)
    {
        int min_over = n, min_pos = 0, currtime = timeline;
        int curr_count = 0;
        for(int i = 0; i < n; i++)
        {
            currtime += m[0];
            for(int j = 0; j < n; j++)
            {
                if(j != i && m[j] + timeline > d[j])
                    curr_count++;                
            }
            if(curr_count < min_over)
            {
                min_over = curr_count;
                min_pos = i;
            }
        }
        
    }
    return 0;
}
