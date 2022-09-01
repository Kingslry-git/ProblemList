#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100;

int leaves[N];
int level[N];
unordered_map<int, vector<int>> mp;

int getId(char id[])
{
    return (10*(id[0] - '0') + id[1] - '0');
}

int main()
{
    cin >> n >> m;
    int idx = 0;
    for(int i = 0; i < m; i ++)
    {
        char c[2];
        scanf("%s",c);
        int id = getId(c);
        int k;
        cin >> k;
        
        for(int j = 0; j < k; j ++)
        {
            char t[2];
            scanf("%s",t);
            int son = getId(t);
            mp[id].push_back(son);
        }
    }

    queue<int> q;
    q.push(1);


    while(q.size())
    {
        int depth = 0;
        int t = q.front();
        q.pop();
       
    //更新layer
        for(auto u : mp[t])
        {
            level[u] = level[t] + 1;
            q.push(u);
        }
        if(!mp[t].size()) leaves[level[t]] ++; 
    }

    int maxH = -1;
    for(int i = 0; i < 100; i ++)
    {
        maxH = max(maxH, level[i]);
    }
    for(int i = 0;i <= maxH; i ++)
    {
        cout << leaves[i];
        if(i != maxH) cout << " ";
    }
    cout << endl;
    return 0;
}