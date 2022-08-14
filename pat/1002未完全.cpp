#include<bits/stdc++.h>

using namespace std;

float co[1010];

int k1,k2;
int min1, min2;
int main()
{
	cin >> k1;
	for(int i = 0; i < k1; i ++)
	{
		int a;
		float b;
		cin >> a >> b;
		co[a] = b;
		min1 = min(min1, a);
	}

	cin >> k2;
	for(int i = 0; i < k2; i ++)
	{
		int a;
		float b;
		cin >> a >> b;
		co[a] += b;
		min2 = min(min1, a);
	}
	int cnt = 0;
	for(int i = 0; i <= 1000; i ++)
		if(co[i] != 0) cnt ++;
	cout << cnt << " ";
	int minx = min(min1, min2);
	for(int i = 1000; i >= 0; i --)
	{
		if(co[i] != 0)
		{
			printf("%d %.1f",i,co[i] );
			if(i != minx && cnt != 0) printf(" ");
		}
	}
	cout << endl;
	return 0;
}