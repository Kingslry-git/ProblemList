#include<bits/stdc++.h>
using namespace std;

int ans;
int x, y;
unordered_set<int> s;

void dfs1(int u)
{
    if(u == 1)
    {
        s.insert(u);
        return;
    }
    else
    {
        if(u % 2 == 1)
        {
            s.insert(u);
            dfs1((u - 1)/2);
        }
        else
        {
            s.insert(u);
            dfs1(u / 2);
        }
    }
}
void dfs2(int u)
{
    if(u == 1)
    {
        ans = u;
        return;
    }
    else
    {
        if(s.count(u))
        {
            ans = u;
            return;
        }
        if(u % 2 == 1)
        {
            dfs2((u-1)/2);
        }
        if(u % 2 == 0)
        {
            dfs2(u/2);
        }
        
    }
}

int main()
{
    cin >> x >> y;
    dfs1(x);
    dfs2(y);
    cout << ans << endl;
    

}

