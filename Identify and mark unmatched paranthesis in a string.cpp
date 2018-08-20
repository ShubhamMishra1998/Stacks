#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void f1(string &s1)
{
	stack<ll> st;
	for (ll i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '(')
			st.push(i);
		else if (s1[i] == ')')
		{
			if (!st.empty())
			{
				s1[st.top()] = '0';
				s1[i] = '1';
				st.pop();
			}
		}
	}
	for (ll i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '0' || s1[i] == '1')
			cout << s1[i];
		else if (s1[i] == ')' || s1[i] == '(')
			cout << "-1";
		else
			cout << s1[i];
	}
}
int main()
{
	string s1;
	cin >> s1;
	f1(s1);
}
