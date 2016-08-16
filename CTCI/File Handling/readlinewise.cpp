#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream read, write("new.txt");
    read.open("InTheEnd.txt");

    string inp;

    while(getline(read, inp))
    {
        cout<<inp<<endl;
        write<<inp<<endl;
    }
    cout<<endl;
    read.close();
    write.close();
    return 0;
}