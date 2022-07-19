#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int q[N], a[N];
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> q[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < i; j ++)
            if(q[j] > q[i]) a[q[i]] ++; 
    int sum = 0;
    for(int i = 1; i <= n;i ++)
    {
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << endl << sum << endl;
    return 0;

}