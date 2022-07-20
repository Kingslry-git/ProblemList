#include<bits/stdc++.h>
using namespace std;
int n, m;
unordered_set<string> h;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        string str;
        cin >> str;
        h.insert(str);
    }
    cin >> m;
    int cnt = 0;
    string a, b;
    for(int i = 0; i < m; i ++)
    {
        string t;
        cin >> t;
        if(h.count(t))
        {
            cnt ++;
            if(a.empty() || a.substr(6,8) > t.substr(6,8))
             a = t;
        }
        else
        {
            if(b.empty() || b.substr(6.8) > t.substr(6,8))
            b = t;
        }
    }
    cout << cnt << endl;
    if(!cnt) cout << b << endl;
    else cout << a << endl;
    return 0;
}