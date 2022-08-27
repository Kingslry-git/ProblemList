#include<bits/stdc++.h>
using namespace std;
string s1, s2;

int main1()
{
    getline(cin, s1);
    istringstream iss;
    iss.str(s1);
    for(int i = 0;i < 4; i ++)
    {
        int val = 0;
        iss >> val;
        cout << val << endl;
    }
    cout << iss.str() << endl;

}
int main()
{
    getline(cin, s1);
    stringstream ss;
    ss.str(s1);
    string word;
    while(ss >> word)
    {
        
        cout << word << endl;
    }
    return 0;
}