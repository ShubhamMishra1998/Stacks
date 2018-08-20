#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void f1(string s1)
{
	if (s1.size() % 2)
	{
		cout << "not possible";
		return;
	}
	vector<ll> m1(100, 0);
	stack<ll> st;
	for (ll i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '(')
			st.push(i);
		else if (s1[i] == ')')
		{
			if (!st.empty())
			{
				m1[i] = 1;
				m1[st.top()] = 1;
				st.pop();
			}
		}
	}
	ll o = 0, c = 0;
	for (ll i = 0; i < s1.size(); i++)
	{
		if (m1[i] == 1)
			continue;
		if (s1[i] == '(')
			o++;
		else if (s1[i] == ')')
			c++;
	}
	if (c % 2)
		cout << ((c + 1) / 2) + ((o + 1) / 2);
	else
		cout << (c / 2) + (o / 2);

	//cout << r;
}
int main()
{
		string s1;
		cin >> s1;
		f1(s1);
}
