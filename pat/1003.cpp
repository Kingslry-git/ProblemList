#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];
int w[N];
int cnt[N], tot[N];//权重，路数，人数
int dist[N];
bool st[N];
int n, m, a, b;

    
void dijkistra()
{

	cnt[a] = 1;
	tot[a] = w[a];
	memset(dist,0x3f, sizeof dist);
	dist[a] = 0;

	for(int i = 0; i < n; i ++)
	{
		int t = -1;
		for(int j = 0;j < n;j ++)
			if(!st[j] && (t == -1 || dist[j] < dist[t] )) t = j;
		
		for(int j = 0;j < n; j ++)
		{
			if(!st[j] && dist[t] + g[t][j] < dist[j])
			{
				dist[j] = dist[t] + g[t][j];
				cnt[j] = cnt[t];
				tot[j] = tot[t] + w[j];
			}
			else if(!st[j] && dist[t] + g[t][j] == dist[j])
			{
				cnt[j] += cnt[t];
				tot[j] = max(tot[j], tot[t] + w[j]);
			}
		}
		st[t] = 1;
	}
}

int main()
{
	cin >> n >> m >> a >> b;
	for(int i = 0; i < n; i ++) cin >> w[i];
	memset(g, 0x3f, sizeof g);
	for(int i = 0 ; i < m; i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = z;

	}
	dijkistra();
	
	cout << cnt[b] << " " << tot[b];
	return 0;
}