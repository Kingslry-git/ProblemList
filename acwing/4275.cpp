//dijkstra算法
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int g[N][N];
bool st[N];
int dist[N];
int q[N];
int n, m, k;

bool dijkstra()
{ 
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    //起点初始化
    dist[q[0]] = 0;    
    for(int i = 0; i < n; i ++)//循环序列次
    {
        int t = q[i];
        for(int j = 1; j <= n;j ++)//j表示节点序号从1~n
            if(!st[j] && dist[j] < dist[t]) return false;
        
        st[t] = true;
        for(int j = 1; j <= n;j ++)
            dist[j] = min(dist[j],dist[t] + g[t][j]);
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = c, g[b][a] = c;
    }
    cin >> k;
    while(k --)
    {
        for(int i = 0; i < n; i ++) scanf("%d",&q[i]);
        for(int i = 0 ;i < n; i ++) printf("%d ",q[i]);
        puts("");
        if(dijkstra()) puts("Yes");
        else puts("No");
    }
    return 0;
}
