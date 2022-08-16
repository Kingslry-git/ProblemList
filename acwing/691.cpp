#include<bits/stdc++.h>
//记忆化搜索
using namespace std;
const int N = 1010;
int g[N][N], f[N][N];
int T, n;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dp(int x, int y)
{
    int &v = f[x][y];
    if(v != -1) return v;
     v = 1;
    for(int i = 0;i < 4; i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < n && g[a][b] == g[x][y] + 1)
        {
             v = max(v,dp(a, b) + 1);
        }
    }
    return v;
}

int main()
{
    cin >> T;
    for(int C = 1; C <= T; C++)
    {
        cin >> n;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                scanf("%d",&g[i][j]);
                
        memset(f, -1, sizeof f);
        int id, cnt = 0;
        
     for(int i = 0; i < n; i ++)
        for(int j = 0;j < n; j ++)
        {
            int t = dp(i, j);
            if(t > cnt || t == cnt && g[i][j] < id)
            {
                id = g[i][j];
                cnt = t;
            }
        }
        printf("Case #%d: %d %d\n",C,id,cnt);
        //cout << g[n - 1][n - 1] << endl;
    }
    return 0;
    
}
