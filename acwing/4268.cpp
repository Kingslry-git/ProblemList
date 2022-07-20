#include<bits/stdc++.h>
using namespace std;

bool is_prime(int u)
{
    if(u < 2) return false;
    for(int i = 2; i <= u / i; i ++)
    {
        if(u % i == 0)  return false;
    }
    return true;
}


int main()
{
    int n;
    cin >> n;

    for(int i = n - 6;i <= n + 6; i += 12)
    {
        if(is_prime(i) && is_prime(n))
        {
            puts("Yes");
            cout << i << endl;
            return 0;
        }
    }
    for(int i = n + 1;;i ++)
    {
        if(is_prime(i) && (is_prime(i-6) || is_prime(i + 6)))
        {
        puts("No");
        cout << i << endl;
        return 0;
        }
    }

}