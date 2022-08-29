#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int q[N];
int n;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i ++) cin >> q[i];

    sort(q,q + n);
    auto k  = unique(q, q + n);
    for(auto t = q; t != k; t ++)
    {
        int p = *t;
        cout << p << " ";
    }
    puts("");
    return 0;

}