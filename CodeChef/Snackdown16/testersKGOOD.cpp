#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstring>

// my input
//abcffggttqqqqqqqqyyyyyyyy 1

using namespace std;

string s;
int k, occ[26];

int main(int argc, const char * argv[]) {
    int tn;
    cin >> tn;
    assert(1 <= tn && tn <= 30);
    while (tn--) {
        cin >> s >> k;
        assert(1 <= s.length() && s.length() <= 100000);
        assert(0 <= k && k <= 100000);
        
        for(int i = 0; i < 26; i++)
            occ[i] = 0;

        for(char c : s) {
            assert('a' <= c && c <= 'z');
            ++occ[c - 'a'];
        }
        
        int ret = (int)s.length();
        
        for(int i = 0; i <= s.length(); i++) {
            int L = i, R = i + k;
            int req = 0;
            
            cout<<"The value for L:"<<L<<"The value of R:"<<R;
            for(int j : occ) if (j != 0) {
                if (j < L)
                    req += j;
                else if (j > R)
                    req += j - R;
                cout<<"\n\tReq:"<<req<<"\tJ value:"<<j<<endl;
            }
                        
            ret = min(ret, req);
        }
        cout << ret << endl;
    }
    return 0;
}
