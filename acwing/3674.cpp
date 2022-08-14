#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> mp;
	mp["one"] = 1;
	mp["zero"] = 0;
	mp["two"] = 2;
	mp["three"] = 3;
	mp["four"] = 4;
	mp["five"] = 5;
	mp["six"] = 6;
	mp["seven"] = 7;
	mp["eight"] = 8;
	mp["nine"] = 9;

    string str;
	while(getline(cin, str))
	{
	    int a = 0, b = 0;
	    stringstream ss(str);
	    string word;
	    while(ss >> word && word != "+")
	    {
	        if(mp.count(word))
	        {
	            a = a * 10 + mp[word];   
	        }
	    }
	    while(ss >> word && word != "=")
	    {
	        if(mp.count(word))
	        {
	            b = b * 10 + mp[word];
	        }
	    }
	    int res = a + b;
	    if(res) cout << res << endl;
	}
	    return 0;
}