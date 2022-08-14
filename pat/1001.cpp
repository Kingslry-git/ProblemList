#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int ans = a + b;
	string res = "";
	if(ans == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(ans < 0)
	{
		ans = abs(ans);
		int cnt = 0;
		while(ans)
		{
			char t = ans % 10 + '0';
			res += t;
			ans /= 10;
			cnt ++;
			cout << cnt << endl;

			if(cnt % 3 == 0 && ans != 0)
			{
				res += ',';
			}
		}
		res.push_back('-');
	}
	if(ans > 0)
	{
		int cnt = 0;
		while(ans)
		{
			char t = ans % 10 + '0';
			res += t;
			ans /= 10;
			cnt ++;
			cout << cnt << endl;

			if(cnt % 3 == 0 && ans != 0)
			{
				res += ',';
			}
		}
	}

	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}