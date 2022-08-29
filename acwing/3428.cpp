#include<bits/stdc++.h>
using namespace std;
int m, n;

int dfs(int d, int sum, int last)
{
    int res = 0;
    if(d == n)
    {
        if(sum == m) return 1;
        else return 0;
    }

    for(int i = last; i <= 10; i ++)
    {
        res += dfs(d + 1, sum + i, i);
    }
    return res;
}

int main()
{
    while(cin >> m >> n) cout << dfs(0,0,0) << endl;
    return 0;
}