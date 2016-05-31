#include<iostream>
#include<vector>

using namespace std;

// taken from geek for geeks perfectly working
long int maxSubArraySum(vector<long int> a)
{
   long int max_so_far = 0, max_ending_here = 0;
   for (unsigned int i = 0; i < a.size(); i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
 
       /* Do not compare for all elements. Compare only   
          when  max_ending_here > 0 */
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        unsigned int n;
        cin>>n;

        vector<long int> a;
        vector<unsigned int> index;
        
        // inputting the numbers in a and creating another vector of the
        // indices of negative value numbers
        for(unsigned int i = 0; i < n; i++)
        {
            long int no;
            cin>>no;
            a.push_back(no);
            if(no < 0)
                index.push_back(i);
        }

        //working perfectly till here
        long int max_sum = a[0];
        // if there is no negative number
        if(index.size() == 0)
        {            cout<<maxSubArraySum(a)<<endl;        }
        // if all numbers are negative
        else if(index.size() == a.size())
        {
            long int max_sum = a[0];
            for(unsigned int i = 1; i < n; i++)
            {
                if(max_sum < a[i])
                    max_sum = a[i];
            }
            cout<<max_sum<<endl;
        }
        // removing one negative number at a time and then finding the maxSubArraySum
        else
        {
            for(unsigned int i = 0; i < index.size(); i++)
            {
                vector<long int>temp;
                temp = a;
                temp.erase(temp.begin() + index[i]);
                //display(temp);
                long int sum = maxSubArraySum(temp);
                if(sum > max_sum)
                    max_sum = sum;
            }
            cout<<max_sum<<endl;
        }    
    }    
    return 0;
}