#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int n, m, k;
bool g[N][N];
bool st[N];

int main()
{
    cin >> n >> m;
    while(m --)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        g[b][a] = g[a][b] = true;
    }
    cin >> k;
    for(int T = 1; T <= k ; T++)
    {
        int num;
        scanf("%d",&num);
        memset(st, 0 ,sizeof st);
        for(int i = 0; i < num; i ++)
        {
            int x;
            scanf("%d",&x);
            st[x] = true;
        }
        bool flag1 = 1;
        for(int i = 1; i <= n; i ++)
            for(int j = i + 1;j <= n; j ++)
                if(st[i] && st[j] && !g[i][j]) flag1 = false;
        if(!flag1) printf("Area %d needs help.\n",T);
        else
        {
           int id = 0;
           for(int i = 1; i <= n ; i ++)
           {
               bool have_all_edges = 1;
               if(!st[i])
               {
                   for(int j = 1; j <= n ; j ++)
                        if(st[j] && !g[i][j]) 
                        {
                            have_all_edges = 0;
                            break;
                        }
                    if(have_all_edges)
                    {
                        id = i;
                        break;
                    }
               }
           }
           if(id) printf("Area %d may invite more people, such as %d.\n",T,id);
           else printf("Area %d is OK.\n",T);
        }
    }
}