#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int l[N], r[N], w[N], idx;
void insert(int &u, int x)
{
    if(!u)
    {
        u = ++idx;
        w[u] = x;
    }
    else if(x < w[u]) insert(l[u], x);
    else if(x > w[u])insert(r[u], x);
    //如果重复插入则什么都不做
}
void dfs(int u, int t)
{
    if(!u) return;
    if(t == 0) cout << w[u] << " ";
    dfs(l[u], t);
    if(t == 1) cout << w[u] << " ";
    dfs(r[u], t);
    if(t == 2) cout << w[u] << " ";

}
int main()
{
    cin >> n;
    int root = 0;
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        insert(root,x);
    }
    for(int i = 0; i < 3;i ++)
    {
        dfs(root, i);
        puts("");
    }
    return 0;
}