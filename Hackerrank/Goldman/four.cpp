#include <bits/stdc++.h>

using namespace std;

void input(vector< pair<int, int> > & tq, int n)
{
    vector<int> time;
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        time.push_back(no);
    }

    vector<int> que;
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        que.push_back(no);
    }

    for(int i = 0; i < n; i++)
    {
        tq.push_back(make_pair(time[i], que[i]));
    }
}

void calc_atleast(vector< pair<int, int> > & tq, vector< pair<int, int> > & atleast)
{
    atleast.push_back(tq[0]);
    int counter = 0;
    for(int i = 1; i < tq.size(); i++)
    {
        if(tq[i].second > atleast[counter].second)
        {
            atleast.push_back(tq[i]);
            counter++;            
        }
    }
}

void calc_atmax(vector< pair<int, int> > & tq, vector< pair<int, int> > & atmax)
{
    int counter = 0;
    atmax.push_back(tq[tq.size() - 1]);
    for(int i = tq.size() - 2; i >= 0; i--)
    {
        if(tq[i].second > atmax[counter].second)
        {
            atmax.push_back(tq[i]);
            counter++;
        }
    }
    reverse(atmax.begin(), atmax.end());
}

void display(vector< pair<int, int> > arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<"\t";
    }
    cout<<endl;
}

int binary_search_price(vector< pair<int, int> > atleast, int data)
{
    int low, high, mid;
    low = 0;
    high = atleast.size() - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(atleast[mid].second < data)
            low = mid + 1;
        else if(atleast[mid].second > data)
            high = mid - 1;
        else
            return mid;
    }
    return mid;
}

int binary_search_time(vector< pair<int, int> > atmax, int data)
{
    int low, high, mid;
    low = 0;
    high = atmax.size() - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(atmax[mid].first < data)
            low = mid + 1;
        else if(atmax[mid].first > data)
            high = mid - 1;
        else
            return mid;
    }
    return mid;
}

int main()
{
    int n, q;
    cin>>n>>q;

    vector< pair<int, int> > tq;
    input(tq, n);

    vector< pair<int, int> > atleast;
    calc_atleast(tq, atleast);

    vector< pair<int, int> > atmax;
    calc_atmax(tq, atmax);

    // display(atleast);
    // display(atmax);

    while(q--)
    {
        int t, v;
        cin>>t>>v;

        if(t == 1)
        {
            int pos = binary_search_price(atleast, v);

            for(; pos < atleast.size(); pos++)
            {
                if(atleast[pos].second >= v)
                    break;
            }

            if(pos == atleast.size())
                cout<<"-1\n";
            else
                cout<<atleast[pos].first<<endl;
        }
        else
        {
            int pos = binary_search_time(atmax, v);

            for(; pos < atmax.size(); pos++)
            {
                if(atmax[pos].first >= v)
                    break;
            }

            if(pos == atmax.size())
                cout<<"-1\n";
            else
                cout<<atmax[pos].second<<endl;

        }
    }

    return 0;
}