#include<iostream>
#include<iomanip>
#include<limits>

using namespace std;

int main()
{
    int i = 4;
    double d = 4.0;
    string s = "HackerRank";
    // Declare second integer, double, and String variables.
    int j;
    double k;
    string str;

    cin>>i>>k;
    cin.ignore(1);
    getline(cin, str);
    // Read and save an integer, double, and String to your variables.
    j += i;
    // Print the sum of both integer variables on a new line.
    k += d;
    // Print the sum of the double variables on a new line.
    string s1;
    s1 = s + str;
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout<<j<<endl<<k<<endl<<s1<<endl;

    return 0;
}