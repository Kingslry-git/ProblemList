#include<bits/stdc++.h>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
//数组模拟
const int N = 1e5 + 10;
int h1, h2, v[N], ne[N];
int n;

int main()
{
    cin >> h1 >> h2 >> n;
    for(int i = 0; i < n; i ++)
    {
        int addr, val, next;
        scanf("%d%d%d",&addr, &val, &next);
        v[addr] = val, ne[addr] = next;
    }

    vector<PII> a, b;
    for(int i = h1; i != -1;i = ne[i])
    {
        a.push_back({i, v[i]});
    }
    for(int i = h2; i != -1;i = ne[i])
    {
        b.push_back({i, v[i]});
    }
    vector<PII> c;
    if(a.size() < b.size()) swap(a,b);

    for(int i = 0, j = b.size() - 1; i < a.size(); i += 2, j --)
    {
        c.push_back(a[i]);
        if(i + 1 < a.size()) c.push_back(a[i + 1]);
        if(j >= 0) c.push_back(b[j]);
    }

    for(int i = 0; i < c.size(); i ++)
    {
        printf("%05d %d ",c[i].x, c[i].y);
        if(i + 1 < c.size()) printf("%05d\n", c[i + 1].x);
        else puts("-1");
    }
    return 0;


}
