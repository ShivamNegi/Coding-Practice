#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;
    long int no;

    cin>>no;

    int counter = -2;
    while(no != 0)
    {
        arr.push_back(no % 10);
        no = no / 10;
        counter ++;
    }

    //display(arr);
    //display is working perfectly.

    int res;
    cin>>res;

    //setting number of operators to the number of spaces
    string ops = "+-*";

    for(int i = 0; i < counter; i++)
    {
        ops = ops + "+-*";  
    }

    // Sorting is important for the next permutation func
    sort(ops.begin(), ops.end());

    string output[2000];
    int outcounter = 0;

    //making all possible combinations for the operators
    do
    {
        bool flag = true;
            //cout<<"\tyes";
        for(int i = 0; i < outcounter; i++)
        {
            if(ops.substr(0, 2) == output[i])
            {
                flag = false;
                break;
            }

        }
        if(flag)
            output[outcounter++] = ops.substr(0, 2);

    }while(next_permutation(ops.begin(), ops.end()) );

    //till here everything is working good.

    for(int j = 0; j < outcounter; j++)
    {
        int no = arr[0];

        for(int i = 0; i <= counter; i++)
        {
            if(output[j][i] == '+')
            {
                no += arr[i + 1];
            }
            else if(output[j][i] == '-')
            {
                no -= arr[i + 1];
            }
            else
            {
                no *= arr[i + 1];
            }
        }

        cout<<"The combination is:"<<output[j]<<"\tThe result is no:"<<no<<endl;

        if(no == res)
        {
            cout<<output[j]<<endl;
        }
    }

    
    cout<<"All the possible combinations.\n";
    for(int i = 0; i < outcounter; i++)
    {
        cout<<output[i]<<endl;
    }


    return 0;
}

/*
 cout<<ops.substr(0, 2);
        int no = arr[0];

        for(int i = 0; i < counter; i++)
        {
            if(ops[i] == '+')
            {
                no += arr[i + 1];
            }
            else if(ops[i] == '-')
            {
                no -= arr[i + 1];
            }
            else
            {
                no *= arr[i + 1];
            }

            cout<<no<<"\t";
        }

        if(no == res)
        {
            
        }
        //cout<<endl;*/