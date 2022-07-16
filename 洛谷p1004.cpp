#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n, f[N][N];
int g[N][N];
int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 0;i < n;i ++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b] = c;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n;j ++)
		{
			if(i == 1)
			{
				f[i][j] = f[i][j - 1] + g[i][j];
			}
			if(j == 1)
			{
				f[i][j] = f[i - 1][j] + g[i][j];
			}
			else
			{
				f[i][j] = max(f[i-1][j]+g[i][j],f[i][j-1]+g[i][j]);
			}
		}
	}
	cout << f[n][n] << endl;
	return 0;
}