#include<bits/stdc++.h>
using namespace std;
int a, b;
string n;

char getC(int x)
{
    if(x >= 0 && x <= 9) return (x + '0');
    else
    {
        return (x - 10 + 'A');
    }
}
int main()
{
    cin >> a >> n >> b;

    //转为10进制
    int decimal = 0;
    for(int i = 0; i < n.size();i ++)
    {
        char t = n[i];
        int num = 0;
        if(t >= 'a' && t <= 'z') num = t - 'a' + 10;
        else if(t >= 'A' && t <= 'Z') num = t - 'A' + 10;
        else num = t - '0';
       //cout  << t << " "<< num << endl;
        decimal = decimal * a + num;
    }
    //cout << decimal << endl;
    //转化为b进制
    string ans = "";
    while(decimal / b)
    {
        int k = decimal % b;
        ans = getC(k) + ans;
        decimal /= b;
    }
    ans = getC(decimal) + ans;

    cout << ans << endl;
    return 0;
}
