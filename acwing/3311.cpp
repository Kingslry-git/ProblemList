#include<bits/stdc++.h>
using namespace std;
const int N = 2E5 + 10;
int a[N];
int T;

int main()
{
    cin >> T;
    
    for(int c = 1; c <= T; c ++)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);

        int cnt = 2;
        int ans = -1;
        int d = a[1] - a[0];
        for(int i = 1; i < n - 1;i ++)
        {
            if(a[i + 1] - a[i] == d)
            {
                cnt ++;
               // cout << "++" << a[i ] << " " << a[i + 1] << endl;
            }
            else
            {
                ans = max(cnt,ans);
                d = a[i + 1] - a[i];
                cnt = 2;
            }
        }
        //此处仍然保留倒数第一项的更新！
        ans = max(ans, cnt);
        printf("Case #%d: %d\n",c, ans);
    }
    return 0;
}
// dp方法
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int A[N],T;
int f[N];
int main()
{
    cin >> T;
    for(int case_ = 1; case_ <= T; case_ ++)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++) scanf("%d",&A[i]);
        
        int ans = -1;
        f[0] = 1;
        for(int i = 1; i < n; i ++)
        {
            if( i > 1 && A[i] - A[i - 1] == A[i - 1] - A[i - 2]) f[i] = f[i - 1] + 1;
            else f[i] = 2;
            ans = max(ans, f[i]);
        }
        printf("Case #%d: %d\n",case_,ans);
    }
    return 0;
}
*/