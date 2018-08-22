#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void removeBeackets(string s1, ll n)
{
	string s2 = "";
	stack<ll> st;
	st.push(0);
	for (ll i = 0; i < n; i++)
	{
		if (s1[i] == '+')
		{
			if (st.top() == 0)
				s2 += "+";
			else if (st.top() == 1)
				s2 += "-";
		}
		else if (s1[i] == '-')
		{
			if (st.top() == 0)
				s2 += "-";
			else if (st.top() == 1)
				s2 += "+";
		}
		else if (s1[i] == '('&&i > 0)
		{
			if (s1[i - 1] == '-')
			{
				if (st.top() == 0)
					st.push(1);
				else
					st.push(0);
			}
			else if (s1[i] == '+')
				st.push(st.top());
		}
		else if (s1[i] == ')')
			st.pop();
		else
			s2 += s1[i];
	}
	cout << s2;
}

int main()
{
	string s1;
	cin >> s1;
	removeBeackets(s1, s1.size());
}
