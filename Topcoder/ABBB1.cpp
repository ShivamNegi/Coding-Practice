#include <bits/stdc++.h>

using namespace std;

class ABBADiv1
{
    bool check_next(string initial, string target)
    {
        if(initial == target)
            return true;
        if(initial.length() == target.length())
            return false;

        string inia = initial + 'a';
        string inib = initial + 'b';
        reverse(inib, inib + inib.length());

        return check_next(inia, target) || check_next(inib, target);
    }   

    string canObtain(string initial, string target)
    {
        if(check_next(initial, target))
            return "Possible";
        return "Impossible";
    }
};