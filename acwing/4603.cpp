#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    cin >> T;
    int n;
    while(T--)
    {
        cin >> n;
        string str;
        scanf("%s", &str[0]);
        
        //右侧P数量
        reverse(&str[0],&str[n]);
        int cntP = 0, maxV = 0;
        for(int i = 0; i < n; i ++)
        {
            if(str[i] == 'P') cntP ++;
            else
            {
                maxV = max(maxV,cntP);
                cntP = 0;
            }
        }
        cout << maxV << endl;

    }
    return 0;
}