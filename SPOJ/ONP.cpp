#include <bits/stdc++.h>

using namespace std;

int get_precedence(char data)
{
    switch(data)
    {
        case '+':
        case '-':
                    return 0;
        case '*':
        case '/':
                    return 1;
        case '^':
                    return 2;
        case '(':
                    return 3;
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp, out = "";
        cin>>inp;

        stack<char> st;
        for(int i = 0; i < inp.length(); i++)
        {
            char data = inp[i];
            if(isalpha(data))
            {
                out += data;
            }
            else
            {
                if(data == '(')
                {
                    st.push('(');
                }
                else if(data == ')')
                {
                    char val = st.top();
                    st.pop();
                    while(val != '(')
                    {
                        out += val;
                        val = st.top();
                        st.pop();
                    }
                }
                else
                {                    
                    int prec = get_precedence(data);
                    while(!st.empty() && prec >= get_precedence(st.top()))
                    {
                        out += st.top();
                        st.pop();
                    }
                    st.push(data);
                }
            }
        }

        while(!st.empty())
        {
            out += st.top();
            st.pop();
        }

        cout<<out<<"\n";
    }
    return 0;
}

