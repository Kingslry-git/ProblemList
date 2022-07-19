#include<bits/stdc++.h>
using namespace std;

int cnt;
int x, y;
unordered_set<int> s;

void dfs(int u)
{
    if(u == 1)
    {
        if(s.count(u)) return;
        else
        {
            cnt ++;
            return;
        }
    }
    else
    {
        if(u % 2 == 1)
        {
            if(s.count(u))
            {
                cnt ++;
                dfs((u-1)/2);
            }
            else
            {
                s.insert(u);
                dfs((u-1)/2);
            }
        }
        else
        {
            if(s.count(u))
            {
                cnt ++;
                dfs(u/2);
            }
            else
            {
                s.insert(u);
                dfs((u/2);
            }
        }
    }
}

int main()
{
    cin >> x >> y;
    dfs(x);
    dfs(y);
    cout << cnt << endl;
    return 0;
}

