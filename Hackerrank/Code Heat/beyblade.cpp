#include <iostream>
#include <cmath>

using namespace std;

int get_gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return get_gcd(b, a % b);
}

int get_len(int x, int y, int l, int r, int t, int b, bool odd)
{
    int points = 0;

    if(odd)
        {
            if(y % 2 == 0)
                points += y / 2 * t + y / 2 * b;
            else
                points += (y / 2 + 1) * t + y / 2 * b; 

            if(x % 2 == 0)
                points += x / 2 * r + x / 2 * l;
            else
                points += (x / 2 + 1) * r + x / 2 * l;
        }
    else
        {
            if(y % 2 == 0)
                points += y / 2 * b + y / 2 * t;
            else
                points += (y / 2 + 1) * b + y / 2 * t; 

            if(x % 2 == 0)
                points += x / 2 * l + x / 2 * r;
            else
                points += (x / 2 + 1) * l + x / 2 * r;

        }   
    return points;
}

int main()
{
    int t, s;
    cin>>t>>s;

    while(t--)
    {
        int p, q, l, r, t, b;
        cin>>p>>q>>l>>r>>t>>b;

        int no_tb, no_lr, gcd;
        float cyclelen;
        long long int points = 0;

        gcd = get_gcd(p, q);        
        cyclelen = (p * q / gcd) * 1.41;

        int nocycles = s / cyclelen;
        float news = fmod(s, cyclelen);

        /*cout<<"cyclelen:"<<cyclelen<<endl;
        cout<<"nocycles:"<<nocycles<<endl;
        cout<<"news:"<<news<<endl;*/

        long long int oddcycle, evencycle;

        //calculating oddcycle
        //this shouldn't be p and q it should be the ratio of the sides
        //the simplest ratio
        int np = p / gcd, nq = q / gcd;
        oddcycle = get_len(np, nq, l, r, t, b, true);
        evencycle = get_len(np, nq, l, r, t, b, false);
        /*cout<<"oddcycle: "<<oddcycle<<"\tevencycle: "<<evencycle<<endl;*/

        long long int revolution = oddcycle + evencycle;
        points = points + (nocycles / 2) * revolution;

        bool left, right, top, bottom;
        left = right = top = bottom = false;

        if(nocycles % 2 == 0)
            {
                no_tb = news / (p * 1.41);
                no_lr = news / (q * 1.41);    

                /*cout<<no_tb<<"\t"<<no_lr<<endl;*/

                points += get_len(no_lr, no_tb, l, r, t, b, true);
            }
            
        
        else
            {
                points += oddcycle;

                if((p / gcd) % 2 == 0)    
                    left = true;
                else
                    right = true;

                if((q / gcd) % 2 == 0)
                    bottom = true;
                else
                    top = true;

                no_tb = news / (p * 1.41);
                no_lr = news / (q * 1.41);

                /*cout<<no_tb<<"\t"<<no_lr<<endl;*/
                
                if(left && bottom)
                {
                    /*cout<<"left & bottom\n";*/
                    points += get_len(no_lr, no_tb, l, r, t, b, true);
                }
                else if(left && top)
                {
                    /*cout<<"left & top\n";*/
                    points += get_len(no_lr, no_tb, l, r, b, t, true);
                }               
                
                else if(right && top)   
                {
                    /*cout<<"right & top\n";*/
                    points += get_len(no_lr, no_tb, r, l, b, t, true);
                }
                else if(right && bottom)
                {
                    /*cout<<"right & bottom\n";*/
                    points += get_len(no_lr, no_tb, r, l, t, b, true);
                }
            }
        cout<<points<<endl;
    }
    return 0;
}