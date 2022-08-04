#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
unordered_set<string> st, de;
int t;
map<string,string> mp;

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i ++)
    {
        mp.clear();
        st.clear();
        de.clear();
        int n;
        cin >> n;
        for(int j = 0 ; j < n; j ++)
        {
            string a = "",b = "";
            cin >> a;
            st.insert(a);
            cin >> b;
            de.insert(b);
            mp[a] = b;
        }
        string s,d;
        for(auto c :st)
        {
            if(!de.count(c)) s = c;
        }
        for(auto c: de)
        {
            if(!st.count(c)) d = c;
        }
        printf("Case #%d: ",i);
        
        while(mp[s] != d)
        {
            printf("%s-%s ",s.c_str(),mp[s].c_str());
            s = mp[s];
        }
        printf("%s-%s\n",s.c_str(),mp[s].c_str());
    }
    return 0;
}