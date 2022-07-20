#include<bits/stdc++.h>
using namespace std;
const int N = 25;
string v[N];
int l[N], r[N];
int root;
bool st[N];//是否有parent节点寻找root
int n;
void dfs(int u)
{
    cout << "(";
    if(l[u] != -1 && r[u] != -1)
    {
        dfs(l[u]);
        dfs(r[u]);
        cout << v[u];
    }
    else if(l[u] == -1 && r[u] == -1)
    {
        cout << v[u];
    }
    else
    {
        cout << v[u];
        dfs(r[u]);
    }
    
    cout << ")";
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) 
    {
        cin >> v[i] >> l[i] >> r[i];
        if(l[i] != -1) st[l[i]] = 1; //确定是否有根节点
        if(r[i] != -1) st[r[i]] = 1;
    }
    for(int i = 1; i <= n; i ++)
        if(!st[i]) root = i;
    dfs(root);
    return 0;
}