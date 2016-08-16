#include <iostream>

using namespace std;

struct rabbit
{
    int no;
    int count;
    bool sleep;
    rabbit * next;
};

rabbit * insertrabit(rabbit * hare)
{
    if(hare)
    {
        rabbit * trav = hare;

        while(trav->next != hare)
            trav = trav->next;

        rabbit * temp = new rabbit;
        temp->no = trav->no + 1;
        temp->count = 0;
        temp->sleep = false;
        temp->next = hare;
        trav->next = temp;

        return hare;
    }
    else
    {
        rabbit * temp;
        temp = new rabbit;
        temp->no = 1;
        temp->count = 0;
        temp->sleep = false;
        temp->next = temp;
        return temp;
    }
}

/*void display(rabbit * rab)
{
    rabbit * head;
    head = rab;

    cout<<head->no<<"\t"<<head->count<<"\n";
    head = head->next;
    while(head != rab)
    {
        cout<<head->no<<"\t"<<head->count<<"\n";
        head = head->next;
    }
}*/

int main()
{
    int p, s;
    cin>>p>>s;

    while(p != 0 && s != 0)
    {
        rabbit * rab = NULL;
        int turcount = 0;

        for(int i = 0; i < p; i++)
        {            rab = insertrabit(rab);        }
        
        int trap[3];

        for(int i = 0; i < 3; i++)
            cin>>trap[i];

        int rounds;
        cin>>rounds;

        int sums[rounds];
        for(int i = 0; i < rounds; i++)
        {
            int a, b;
            cin>>a>>b;
            sums[i] = a + b;
        }
        for(int i = 0; i < rounds; i++)
            {                
                int sum = sums[i];
                /*cout<<"here\n";*/

                while(rab->sleep == true)
                    {
                        rab->sleep = false;
                        rab = rab->next;
                    }

                rab->count += sum;
                turcount++;

                for(int j = 0; j < 3; j++)
                {
                    if(rab->count == trap[j])
                    {
                        rab->sleep = true;
                        break;
                    }
                }

                if(turcount > s || rab->count > s)
                    break;

                /*display(rab);*/
                rab = rab->next;
            }

        if(turcount > s)
        {            cout<<"Turtle wins!\n";        }
        else if(rab->count > s)
        {            cout<<"Rabbit: "<<rab->no<<endl;           }

        cin>>p>>s;
    }
    return 0;
}