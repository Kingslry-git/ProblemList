#include<bits/stdc++.h>
using namespace std;
const int N = 310;
int g[N][N];
int f[N][N];
int m, n;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int dp(int a, int b)
{
    int &v = f[a][b];
    if(v != -1) return v;
    
     v = 1;
    for(int i = 0; i < 4; i ++)
    {
        int x = a + dx[i], y = b + dy[i];
        if(x >= 0 && x < m && y >= 0 && y < n && g[x][y] < g[a][b])
        {
            v = max(v, dp(x, y) + 1);//状态迁移方程从后一步往前！
        }
    }
    return v;
}


int main()
{
  
    cin >> m >> n;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
            scanf("%d",&g[i][j]);
            
    memset(f, -1, sizeof f);
    
    int res = 0;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
            res = max(dp(i, j), res);
    cout << res << endl;
    return 0;
}
