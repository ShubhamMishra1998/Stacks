#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxLength(string s1)
{
	ll n = s1.length(), m = 0;
	stack<ll> st;
	st.push(-1);
	for (ll i = 0; i < n; i++)
	{
		if (s1[i] == '(')
			st.push(i);
		else if (s1[i] == ')')
		{
			st.pop();
			if (!st.empty())
				m = max(m, i - st.top());
			else
				st.push(i);
		}
	}
	return m;
}

int main()
{
	string s1;
	cin >> s1;
	cout << maxLength(s1);
}
