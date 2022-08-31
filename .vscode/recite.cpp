#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int dist[N];
int g[N][N];
bool st[N];
int n, m;
void dijkistra() //O(n^2)
{
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;

    for(int i = 0; i < n;i ++)
    {
        int t = -1;
        for(int j = 0; j < n; j ++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
            t = j;

            st[t] = 1;//拓展完之后标记

            if(!st[j]&& dist[t] + g[t][j] < dist[j])
            {
                dist[j] = dist[t] + g[t][j];
            }
        }
    }
}

int spfa()
{
    int h[N], ne[N], e[N], idx;
    /*
    void add(int a, int b)
    {
        e[idx] = b;
        ne[idx] = h[a];
        w[idx] = X;
        h[a] = idx ++;
    }
    */
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = 1;

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = 0;

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[i] + w[i])
            {
                dist[j] = dist[i] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = 1;
                }

            }
        }
    }
    return dist[n - 1];
}

void bf()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    int backup[N];
        struct Edge
    {
        int a, b, c;
    }edges[N];
    int k;//选k条边
    int m;//有m条边
    for(int i = 0;i < k;i ++)
    {
        memcpy(backup, dist, sizeof backup);
        for(int j = 0;j < m; j ++)
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], dist[e.a] + e.c);   
        }
    }//判断
}