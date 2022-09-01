#include<bits/stdc++.h>
using namespace std;
string N;
int sum;
int digit[110];

string outpr(int num)
{
    string re;
    switch (num)
    {
    case 1: 
        re = "one";
        break;
     case 0: 
        re = "zero";
        break;
     case 2: 
        re = "two";
        break;
     case 3: 
        re = "three";
        break;
     case 4: 
        re = "four";
        break;
     case 5: 
        re = "five";
        break;
      case 6: 
        re = "six";
        break;
     case 7: 
        re = "seven";
        break;
     case 8: 
        re = "eight";
        break;
     case 9: 
        re = "nine";
        break;   
    }
    return re;
}
int main()
{
    cin >> N;
    for(int i = 0; i < N.size(); i ++)
    {
        sum += N[i] - '0';
    }
    int idx = 0;
    if(sum == 0)
    {
        cout << "zero" << endl;
        return 0;
    }
    while(sum)
    {
        int t = sum % 10;
        sum /= 10;
        digit[idx++] = t;
    }
    for(int i = idx - 1; i >= 0; i --)
    {
        cout << outpr(digit[i]);
        if(i != 0) cout << " ";
    }
    puts("");
    return 0;

}