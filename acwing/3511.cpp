#include<bits/stdc++.h>
using namespace std;
int v[3];
typedef long long LL;
const LL B = 10000;
unordered_set<int> cs;
unordered_set<LL> states;

//得到状态数
LL getNum(int a[])
{
    return a[0] * B * B + a[1] * B + a[2];
}

//数组状态变化
void pour(int c[], int i,int j)
{
    int trans = min(c[i], v[j] - c[j]);
    c[i] -= trans;
    c[j] += trans;
}

void dfs(int c[])
{
    states.insert(getNum(c));
    cs.insert(c[2]);

    int t[3];
    for(int i = 0; i < 3; i ++)
        for(int j = 0;j < 3; j ++)
            if(i != j )
            {
                memcpy(t, c, sizeof t);
                pour(t, i, j);
                if(!states.count(getNum(t)))
                dfs(t);
            }
}

int main()
{
    while(cin >> v[0] >> v[1] >> v[2])
    {
        cs.clear();
        states.clear();
        int c[3] = {0, 0, v[2]};
        dfs(c);
        cout << cs.size() << endl;
    }
    return 0;
}