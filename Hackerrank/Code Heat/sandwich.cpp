/*
    This algorithm is right. The distance between the two points is greatest, that means
    we have to first focus on reducing that. We do this by finding the mid point of the
    two points of the greatest distance and then try to reduce it by making a city closest
    to it as a stoppage point.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
*/

// this function returns the maximum distance point starting,
// i.e. the maximum distance is between the point pos and pos + 1
int max_diff_pos(vector<long long int> a)
{
    long long int diff = 0; 
    int pos;

    for(int i = 0; i < a.size() - 1; i++)
    {
        if(a[i + 1] - a[i] > diff)
            {
                diff = a[i + 1] - a[i];
                pos = i;
            }
    }

    return pos;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int p, x;
        cin>>p>>x;

        long long int a[p];
        // inputting the city locations
        for(int i = 0; i < p; i++)
            cin>>a[i];

        vector<long long int> halts;
        halts.push_back(a[0]);
        halts.push_back(a[p - 1]);

        // we try to make x - 1 paths in the middle cause the first and
        // the last point have to joint making it one path
        for(int i = 0; i < x - 1; i++)
        {
            int pos = max_diff_pos(halts);
            long long int mid = (halts[pos + 1] + halts[pos]) / 2;
            int j;

            for(j = 0; j < p; j++)
            {
                if(mid < a[j])
                    break;
            }

            long long int ele;
            if(a[j] != halts[pos + 1])                        
                ele = (mid - a[j - 1]) < (a[j] - mid)? a[j - 1]: a[j];            
            else if(a[j - 1] != halts[pos])
                ele = a[j - 1];
            else
            {
                // now there is this problem,,what if there is no point
                // in between the points that have the largest distance
                // then in that case I can't do anythin actually
                break;
            }

            for(j = 0; j < halts.size(); j++)
            {
                if(halts[j] > ele)
                    break;
            }
            halts.insert(halts.begin() + j, ele);
        }

        int pos = max_diff_pos(halts);
        long long int max_dist = halts[pos + 1] - halts[pos];        
        cout<<max_dist<<endl;
        /*display(halts);*/
    }
    return 0;
}