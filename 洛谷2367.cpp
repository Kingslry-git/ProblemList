#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int a[N];
int b[N];
int n, p;
void insert(int x)
{
	b[x] = a[x] - a[x - 1];
}

int main()
{
	cin >> n >> p;
	for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);

	for(int i = 1; i <= n ;i ++)
	{
		insert(i);
	}
	while(p --)
	{
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		b[x]+=z, b[y+1]-=z;
	}
	int sum = 0, res = 1e9;
	for(int i = 1; i <= n; i ++)
	{
		sum += b[i];
		res = min(res, sum);
	}
	cout << res << endl;
	return 0;
}