#include<bits/stdc++.h>
using namespace std;

//huffman tree addSum
priority_queue<int,vector<int>,greater<int> > q;
int n;
int main()
{
    int res = 0;
    cin >> n;
    for(int i = 0; i < n ;i ++) 
    {
        int t;
        scanf("%d",&t);
        q.push(t);
    }

    while(q.size() > 1)//关键 否则pop不可以出两个！
    {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        res += (a + b);
        q.push(a + b);
    }
    cout << res << endl;
    return 0;
}