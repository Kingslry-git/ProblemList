#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q[N], w[N], ne[N];
int h;

int main()
{
    int n, k;
    cin >> h >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        int add, v, next;
        scanf("%d%d%d",&add,&v,&next);
        w[add] = v;
        ne[add] = next;
    }
    
    //从头遍历
    int cnt = 0;
    for(int i = h; i != -1; i = ne[i])
    {
        q[cnt ++] = i;
    }

    reverse(q,q + cnt);

    //reverse妙用
    for(int i = cnt - 1; i >= 0; i -= k) reverse(q + max(0,(i - k + 1)), q + i + 1);

    for(int i = 0; i < cnt; i ++)
    {
        int addr = q[i], next = q[i + 1];
        printf("%05d %d ",addr, w[addr]);
        if(i == cnt - 1) puts("-1");
        else printf("%05d\n",next);
    }
    return 0;
}