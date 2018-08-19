#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxDepth(string s1)
{
	ll m = 0, c = 0;
	for (ll i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '(')
		{
			c++;
			if (c > m)
				m = c;
		}
		else if(s1[i]==')')
		{
			if (c > 0)
				c--;
			else
				return -1;
		}
	}
	if (c != 0)
		return -1;
	else
		return m;
}
int main()
{
	string s1;
	ll a;
	cin >> s1;
	a = maxDepth(s1);
	if (a != -1)
		cout << a << ' ';
	else
		cout << "NOT BALANCED";
}
